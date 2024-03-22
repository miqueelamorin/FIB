# PRACTICA 1 #######################

	.data
A: .word 3,5,7
punter: .word 0

	.text
	.globl main
main:
	la $t1, A		#carregar adreça de A
	addiu $t1, $t1, 8 	#calcular A[2]
	la $t0, punter		#carregar adreça de punter
	sw $t1, 0($t0)		#guardar el valor de A[2] a punter
	
	lw $t2, 0($t0)		#llegir l'adreça que conté punter emmagatzemada
	lw $t0, 0($t2)		#accedir al valor que conté l'adreça
	addiu $s0, $t0, 2	#sumar 2 al valor
	
	lw $t2, -8($t2)		#llegir el valor de l'adreça de punter -2
	addu $s0, $t2, $s0	#sumar-li la variable temp
	
	sw $s0, 4($t1)		#A[1] = temp
	
	li $v0,1		#Indicar que volem fer una instrucció de print integer
	move $a0, $s0		#Carreguem el valor de temp a la variable a0
	syscall			#Crida al sistema

	jr $ra		# main retorna al codi de startup

