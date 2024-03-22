	# Sessio 3

	.data 
	.align 2
mat1:   .space 120
mat4:   .word 2, 3, 1, 2, 4, 3
col:   	.word 2

	.text 
	.globl main
main:
	addiu $sp, $sp, -4	#reservem espai a la pila per $ra
	sw $ra, 0($sp)

	la $t0, col		#guardem el valor de col a $a2
	lw $a2, 0($t0)
	
	la $a0, mat4		#$a0 = @mat
	lw $a1, 8($a0)		#$a1 = mat[0][2]
	
	jal subr		#cridem a subr
	
	la $t0, mat1	
	sw $v0, 108($t0)	#mat[4][3] = $v0

	la $a0, mat4			
	li $a1, 1		
	li $a2, 1
	
	jal subr
				
	la $t0, mat1			
	sw $v0, 0($t0)		#mat1[0][0] = $v0

	lw $ra, 0($sp)			
	addiu $sp, $sp, 4

	jr $ra	
	
subr:
	la $t0, mat1		#calculem mat1[j][5] = @mat1 + 4*(j*6+5)
	li $t1, 6		
	mult $a2, $t1		
	mflo $t1		#j*6
	addiu $t1, $t1, 5	#(j*6+5)
	sll $t1, $t1, 2		#(j*6+5)*4
	addu $t0, $t0, $t1	#@mat[j][5]	

	li $t1, 3		#calculem mat4[i][j] = @mat + 4*(i*3+j)
	mult $t1, $a1		
	mflo $t1		#1*3
	addu $t1, $t1, $a2	#(1*3+1)
	sll $t1, $t1, 2		#(1*3+1)*4
	addu $t1, $a0, $t1	#@mat4[i][j]	

	lw $t1, 0($t1)		#$t1 = mat4[i][j]
	sw $t1, 0($t0)		#mat1[j][5] = mat4[i][j]
	move $v0, $a1

	jr $ra				


