        .global lrintf
        .align 16, 0x90
        .type lrintf,@function
lrintf:
	cvtss2si %xmm0,%rax
	#ret
        popq %rcx
        movl %ecx, %ecx
try:    movq %gs:0x1000, %rdi
__mcfi_bary_lrintf:
        cmpq %rdi, %gs:(%rcx)
        jne check
        jmpq *%rcx
check:
        movq %gs:(%rcx), %rsi
        testb $0x1, %sil
        jne die
        cmpl %esi, %edi
        jne try
die:
        hlt
        .section	.MCFIFuncInfo,"",@progbits
	.ascii	"{ lrintf\nY i64!float@\nR lrintf\n}"
	.byte	0
