.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

    movl $0, -4(%ebp)       #res=0
    movl $0, %ebx           #i = 0
fori:
    cmpl $3, %ebx
    jge fifori
    movl $0, %esi           #j=0

forj:
    cmpl $3, %esi
    jge fiforj

    imul $3, %ebx, %edi     #edi=i*3
    addl %esi, %edi         #i*3+j
    movl 8(%ebp), %ecx      #+@M
    movl (%ecx,%edi,4), %edi       #accedim
    addl %edi, -4(%ebp)     #res+=acces

    addl 12(%ebp), %esi     #j+=salto
    jmp forj

fiforj:
    addl 12(%ebp), %ebx     #i+=salto
    jmp fori
fifori:


# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
