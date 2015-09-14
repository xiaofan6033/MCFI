        .global atanl
        .align 16, 0x90
        .type atanl,@function
atanl:
	fldt 8(%rsp)
	fld1
	fpatan
	#ret
        popq %rcx
        movl %ecx, %ecx
try:    movq %gs:0x1000, %rdi
__mcfi_bary_atanl:
        movq %gs:(%rcx), %rsi
        cmpq %rdi, %rsi
        jne check
        # addq $1, %fs:0x108 # icj_count
        jmpq *%rcx
check:
        testb $0x1, %sil
        jz die
        cmpl %esi, %edi
        jne try
die:
        leaq try(%rip), %rdi
        jmp __report_cfi_violation_for_return@PLT

        .section	.MCFIFuncInfo,"",@progbits
	.ascii	"{ atanl\nY x86_fp80!x86_fp80@\nR atanl\n}"
	.byte	0
