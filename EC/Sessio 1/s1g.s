# PRACTICA 1 #######################

	.data
Fib: .space 40

	.text
	.globl main
main:
	li $s0, 2		#i=2
	la $t1, Fib		#carreguem l'adreça de Fib
	sw $zero, 0($t1)	#Fib[0] = 0
	li $t2, 1		#carreguem un 1 immediat
	sw $t2, 4($t1)		#Fib[1] = 1
	
while:
	slti $t0, $s0, 10	
	beq $t0, $zero, fi
	
	sll $t2, $s0, 2		#calculem i per words (i*4)
	addu $t0, $t1, $t2	#Calculem l'adreça de fib[i]
	lw $t2, -4($t0)		#llegim el que hi ha emmagatzemat a fib[i-1]
	lw $t3, -8($t0)		#fem el mateix per fib[i-2]
	addu $t2, $t2, $t3	#sumem els dos valors
	sw $t2, 0($t0)		#els guardem a fib[i] 
	
	addiu $s0, $s0, 1	#++i
	b while
	
fi:

	jr $ra		# main retorna al codi de startup

