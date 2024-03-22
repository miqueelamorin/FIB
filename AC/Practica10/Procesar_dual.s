.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
    movl $0, %eax
    movl 16(%ebp), %ecx
    imull %ecx, %ecx
    movl 12(%ebp), %esi
    movl 8(%ebp), %ebx

    movl %ebx, %edi
    andl $15, %edi  #matA
    jne for_no_alineat

    movl %esi, %edi
    andl $15, %edi  #matB
    jne for_no_alineat

for_alineat:
    cmpl %ecx, %eax
    jge end

    movdqa (%ebx, %eax), %xmm0
    psllq $4, %xmm0
    movdqa %xmm0, (%esi, %eax)

    addl $16, %eax
    jmp for_alineat

for_no_alineat:
    cmpl %ecx, %eax
    jge end

    movdqu (%ebx, %eax), %xmm0
    psllq $4, %xmm0
    movdqu %xmm0, (%esi, %eax)

    addl $16, %eax
    jmp for_no_alineat
end:


# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
