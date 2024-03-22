.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)

# Aqui has de introducir el codigo

    movl $1, %ebx           #i=1

for:
    cmpl 12(%ebp), %ebx     #i<elementos
    jge fifor

    movl 8(%ebp), %edi      #@vec
    movl (%edi,%ebx,4), %esi
    cmpl %esi, -4(%ebp)    #vec[i]>res
    jge end_if

    movl %esi, -4(%ebp)     #res=vec[i]
end_if:
    incl %ebx                #++i
    jmp for
fifor:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
