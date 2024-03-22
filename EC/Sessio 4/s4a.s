	.data
signe:		.word 0
exponent:	.word 0
mantissa:	.word 0
cfixa:		.word 0x00000000#87D18A00
cflotant:	.float 0.0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)

	la	$t0, cfixa
	lw	$a0, 0($t0)
	la	$a1, signe
	la	$a2, exponent
	la	$a3, mantissa
	jal	descompon

	la	$a0, signe
	lw	$a0,0($a0)
	la	$a1, exponent
	lw	$a1,0($a1)
	la	$a2, mantissa
	lw	$a2,0($a2)
	jal	compon

	la	$t0, cflotant
	swc1	$f0, 0($t0)

	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra


descompon:
	li $t0, 0
	slt $t1, $a0, $t0		#Val 1 si és negatiu, 0 si no
	sw $t1, 0($a1)			#Guardem el resultat de la comparació
	sll $a0, $a0, 1			#Eliminem el signe
	
	beq $a0, $t0, end		#Si la coma fixa és 0, exp i mantissa = 0
	
	li $t1, 18
while: 					
	blt $a0, $t0, fi
	sll $a0, $a0, 1			#Normalitzem la mantissa
	addiu $t1, $t1, -1		#i ajustem l'exponent
	b while
	
fi:  
	li $t0, 0x7FFFFF
	srl $a0, $a0, 8			#Alineem
	and $a0, $a0, $t0		#i eliminem el bit ocult
	addiu $t1, $t1, 127		#Codifiquem l'exponent en excés 127
	
end:	sw $t1, 0($a2)			#Guardem l'exponent
	sw $a0, 0($a3)			#Guardem la mantissa
	
	jr $ra
	
compon:
	sll $a0, $a0, 31		#Desplaçem el signe 31 bits 
	sll $a1, $a1, 23		#Desplaçem l'exponent 23 bits 
	or $v0, $a0, $a1		#Unim el signe, l'exponent
	or $v0, $v0, $a2		#i la mantissa
	mtc1 $v0, $f0			#Guardem el resultat al coprocessador 1
	jr $ra

