 .text
	.align 4
	.globl Intercambiar
	.type Intercambiar,@function
Intercambiar:
        # Aqui viene vuestro codigo
        pushl %ebp
        movl %esp, %ebp
        subl $12, %esp

        pushl %ebx
        pushl %esi

        imul $12, 12(%ebp), %eax        #eax = i*12
        imul $12, 16(%ebp), %ecx        #ebx = j*12

        addl 8(%ebp), %eax              #eax = v[i]
        addl 8(%ebp), %ecx              #ebx = v[j]

        movb (%eax), %bl                #cl = v[i].c
        movb (%ecx), %dl                #dl = v[j].c
        movb %dl, (%eax)                 #v[i].c = v[j].c
        movb %bl, (%ecx)                 #v[j].c = v[i].c

        movl 4(%eax), %edx              #edx = v[i].k
        movl 4(%ecx), %esi              #esi = v[j].k
        movl %esi, 4(%eax)              #v[i].k = v[j].k
        movl %edx, 4(%ecx)              #v[j].k = v[i].k

        movl 8(%eax), %edx              #edx = v[i].m
        movl 8(%ecx), %esi              #esi = v[j].m
        movl %esi, 8(%eax)              #v[i].m = v[j].m
        movl %edx, 8(%ecx)              #v[j].m = v[i].m

        popl %ebx
        popl %esi

        movl %ebp, %esp
        popl %ebp
        ret
