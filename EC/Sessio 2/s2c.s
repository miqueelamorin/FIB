	.data
w:        .asciiz "8754830094826456674949263746929"
resultat: .byte 0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4	#reduïm l'stack pointer 1 word
	sw	$ra, 0($sp)	#guardem al stack pointer l'adreça de retorn
	la	$a0, w		#$a0 = @w
	li	$a1, 31		#$a1 = 31 = nombre d'elements a analitzar
	jal	moda		#cridem a la funcio moda amb w i 31
	
	la	$s0, resultat	#guardem al registre segur s0 l'@ de resultat
	sb	$v0, 0($s0)	#guardem a s0 el resultat de cridar a moda
	
	move	$a0, $v0	#el caràcter a imprimir el passem a a0
	li	$v0, 11		#v0 = 11
	syscall			#cridem a la funcio d'imprimir caràcters
	lw	$ra, 0($sp)	#restaurem l'adreça de retorn
	addiu	$sp, $sp, 4	#tornem l'stack pointer al seu estat inicial
	jr 	$ra		#saltem a ra

nofares:
	li	$t0, 0x12345678
	move	$t1, $t0
	move	$t2, $t0
	move	$t3, $t0
	move	$t4, $t0
	move 	$t5, $t0
	move	$t6, $t0
	move 	$t7, $t0
	move 	$t8, $t0
	move 	$t9, $t0
	move	$a0, $t0
	move	$a1, $t0
	move	$a2, $t0
	move	$a3, $t0
	jr	$ra


moda:
	addiu $sp, $sp, -60	#reservem espai a l'stack pointer pel vector histo (40) i 20 per s0-s3 i ra 
	sw $ra, 40($sp)		
	sw $s0, 44($sp)		#l'utilitzarem per la variable max
	sw $s1, 48($sp)		#guardarem @w[0]
	sw $s2, 52($sp)		#aqui passarem el 31
	sw $s3, 56($sp)		#aquest serà el nostre comptador
	move $s1, $a0		#s1 = @w[0]
	move $s2, $a1		#s2 = 31
	
	move $s3, $zero		#s3 serà el comptador
	li $t7, 10
	
firstloop:			#primer bucle de 10 iteracions
	bge $s3, $t7, fi	#si comptador >= 10 acabem la execucio
	sll $t5, $s3, 2		#calculem la nova adreça a inicialitzar a la iteració actual
	addu $t6, $sp, $t5	#sumem l'adreça inicial de histo i el desplaçament anterior i ho guardem a t6
	sw $zero, 0($t6)	#incialitzem a 0 l'adreça donada
	addiu $s3, $s3, 1
	b firstloop
	
fi:
	li $t4, '0'
	move $s3, $zero		#nou comptador a 0
	
secondloop:
	bge $s3, $s2, fi2	#si s1 >= 31 saltem a fi2
	move $a0, $sp		#a0 = l'adreça incial del vector histo
	addu $a1, $s1, $s3	#sumem a l'adreça incial de w el valor de la iteració per calcular l'adreça
	lbu $a1, 0($a1)		#llegim el valor de w[k]
	subu $a1, $a1, $t4	#li restem un caràcter '0'
	subu $a2, $s0, $t4	#a la variable max li restem '0'
	jal update		#cridem a update amb (histo(a0), vec[k]-'0'(a1), max-'0'(a2))
	
	addu $s0, $v0, $t4	#guardem a max el resultat d'update + '0'
	addiu $s3, $s3, 1	#++comptador
	j secondloop

fi2:
	move $v0, $s0		#retornem max
	lw $ra, 40($sp) 	#restaurem les variables
	lw $s0, 44($sp)
	lw $s1, 48($sp)
	lw $s2, 52($sp)
	lw $s3, 56($sp)
	addiu $sp, $sp, 60	#alliberem espai de l'stack pointer
	jr $ra
	
update:
	addiu $sp, $sp, -16	#fem backup de les variables i preparem l'sp
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $s2, 12($sp)
	move $s0, $a0		#*h
	move $s1, $a1		#i
	move $s2, $a2		#imax
		
	jal nofares
	
	sll $t3, $s1, 2		#guardem a t3 el desplaçament del vector (*4)
	addu $t3, $s0, $t3	#li sumem a l'@ inicial de h el desplaçament
	lw $t5, 0($t3)		#t5 = h[i]
	addiu $t7, $t5, 1	#t7 = h[i]++
	sw $t7, 0($t3)		#t3 = h[i]++
	
	sll $t6, $s2, 2		#calculem el desplaçament respecte imax
	addu $t4, $s0, $t6	#calculem l'@ a llegir
	lw $t4, 0($t4)		#t4 = h[imax]
	
	move $v0, $s1		#retornem i
	bgt $t5, $t4, final	#si h[i] > h[imax] ja hem acabat
	move $v0, $s2		#retornem imax
	
final:
	
	lw $s2, 12($sp)		#restaurem valors
	lw $s1, 8($sp)
	lw $s0, 4($sp)
	lw $ra, 0($sp)
	addiu $sp, $sp, 16	#alliberem l'sp
	
	jr $ra

