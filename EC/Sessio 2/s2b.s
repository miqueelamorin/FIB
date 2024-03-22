.data
result: .word 0
num: .byte ';'

.text
.globl main

main:
la $t0, num	#carreguem l'adreça de num
lb $t0, 0 ($t0)	#carreguem el valor de num
la $t1 , result	#carreguem l'adreça de result

li $t2, 'a'	#$t2 = 'a'
blt $t0, $t2, or1	#si num < 'a' evaluem després de l'or
li $t2, 'z'	#$t2 = 'z'
ble $t0, $t2, etiq1	#si num <= 'z' efectuem l'operacio

or1:
li $t2, 'A'	#$t2 = 'A'
blt $t0, $t2, else1	#si num < 'A' passem al else per comprovar si es un numero
li $t2, 'Z'	#$t2 = 'Z'
bgt $t0, $t2, else1	#si num > 'Z' passem al else per comprovar si es un numero

etiq1:
move $t1, $t0	#result = num
b fi	#hem acabat

else1:
li $t2, '0'	#$t2 = '0'
blt $t0, $t2, else2	#si num < '0' saltem al segon else per fer result = -1
li $t2, '9'	#$t2 = '0'
bgt $t0, $t2, else2	#si num > '9' saltem al segon else per fer result = -1

li $t2, '0'	#$t2 = '0'
subu $t1, $t0, $t2	#result = num - '0'
b fi	#hem acabat

else2:
li $t2, -1	#$t2 = -1
move $t1, $t2	#result = -1

fi:
jr $ra