 .text
	.align 4
	.globl Ordenar
	.type Ordenar,@function
Ordenar:
        pushl %ebp
        movl %esp, %ebp
        subl $8, %esp

        pushl %ebx
        pushl %esi
        pushl %edi

        movl 8(%ebp), %edi                  #edi = @v
        movl $0, %ebx                       #ebx = i = 0

fori:   imul $12, %ebx, %eax                #i*12
        cmpl $0x80000000, 4(%edi, %eax)     #v[i].k == 0x80000000
        je fifori

        movl %ebx, %esi                     #j = i
        incl %esi                           #++j

forj:   imul $12, %esi, %eax                #j*12
        cmpl $0x80000000, 4(%edi, %eax)     #v[i].k == 0x80000000
        je fiforj

        imul $12, %ebx, %ecx                #i*12
        movl 4(%edi, %ecx), %edx            #edx = v[i].k
        cmpl %edx, 4(%edi, %eax)            #v[j].k >= v[i].k
        jge fi_if

        pushl %esi                          #j
        pushl %ebx                          #i
        pushl %edi                          #v[]
        call Intercambiar
        addl $12, %esp

fi_if:  incl %esi                           #++j
        jmp forj

fiforj: incl %ebx                           #++i
        jmp fori

fifori: movl %ebx, %eax                     #eax = i

        popl %ebx
        popl %esi
        popl %edi

        movl %ebp, %esp
        popl %ebp
        ret
