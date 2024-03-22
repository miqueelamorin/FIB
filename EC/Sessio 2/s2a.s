	.data

	.text
	.globl main
main:
	li $s1, 23 # Y
	li $s0, 8  # X

	li $t0, 1	#t0 = 1
	sllv $t0, $t0, $s0	#fem un desplaçament de 0x01 tants bits com X a l'esquerra $t0 = 1<<X
	addi $t0, $t0, -1	#li restem 1 al valor $t0 = (1<<X)-1
	xor $s1, $s1, $t0	#fem una XOR de Y amb $t0 i ho guardem a Y; Y = Y ^ ((1<<X)-1)


	jr $ra
