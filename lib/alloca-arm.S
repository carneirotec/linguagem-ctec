	.text
	.align	2
	.global	alloca
	.type	alloca, %function
alloca:
#se_definido __TINYC__
        .inteiro 0xe060d00d
        .inteiro 0xe3cdd007
        .inteiro 0xe1a0000d
        .inteiro 0xe1a0f00e
#senão
	rsb	sp, r0, sp
	bic	sp, sp, #7
	mov	r0, sp
	mov	pc, lr
#fim_se
	.size	alloca, .-alloca
