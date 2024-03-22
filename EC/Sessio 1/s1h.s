# PRACTICA 1 #######################

	.data
cadena: .byte -1,-1,-1,-1,-1,-1
	.align 2
vec:	.word 5,6,8,9,1

	.text
	.globl main
main:
	li $s0, 0		#i=0
	
while:
	li $t0,5		
	bge $s0, $t0, fi
	
	la $t2, vec		#carreguem l'adreça de vec
	li $t3, 4		#carreguem un immediat 4
	subu $t3, $t3, $s0	#restem 4-i
	sll $t3, $t3, 2		#la multipliquem per 4 perquè treballem amb words
	addu $t2, $t2, $t3	#calculem l'adreça de vec[4-i]
	lw $t2, 0($t2)		#accedim a vec[4-i]
	addiu $t2, $t2, 48	#li sumem el caràcter 0
	
	la $t1, cadena		#carreguem l'adreça de cadena
	addu $t1, $t1, $s0	#la sumem a l'adreça base de cadena
	sb $t2, 0($t1)		#guardem a cadena[i] el valor de $t2
		
	addiu $s0, $s0, 1	#++i
	b while
	
fi:
	la $t0, cadena		#carreguem l'adreça de cadena en t0
	sb $zero, 5($t0)	#posem el sentinella en cadena[5]
	
	li $v0, 4		#operació print string
	move $a0, $t0		#movem a a0 el string cadena
	syscall			#syscall per imprimir-lo
	
	jr $ra		# main retorna al codi de startup

