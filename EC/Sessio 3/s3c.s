	# Sessio 3

	.data 
mat:	.word 0,0,2,0,0,0
	.word 0,0,4,0,0,0
	.word 0,0,6,0,0,0
	.word 0,0,8,0,0,0
resultat: .word 0

	.text 
	.globl main
main:
	addiu $sp,$sp,-4	#reservem espai per $ra
	sw $ra,0($sp)
	
	la $a0,mat		#a0 = @mat
	jal suma_col
	
	la $t0, resultat
	sw $v0, 0($t0)		#guardem el resultat en la var resultat
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4	#deixem la pila com estava
	jr $ra

suma_col:
	li $t0,0		#i = 0
	li $t1,4		#t1 = 4
	li $v0,0		#suma = 0
	addiu $a0, $a0, 8	#@mat[0][2]
	
bucle:	
	beq $t0,$t1,fi		#salta si i = 4
	lw $t3,0($a0)		#t3 = mat[i][2]
	addu $v0, $v0, $t3	#suma += mat[i][2]
	addiu $a0, $a0, 24	#sumem stride
	addiu $t0, $t0, 1	#++i
	b bucle
	
fi:	jr $ra

	




