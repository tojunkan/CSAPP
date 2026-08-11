	.file	"transpose.c"
	.text
	.globl	transpose
	.type	transpose, @function
transpose:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %r8
	movq	%rdi, %r10
	movl	$0, %r9d
	jmp	.L2
.L10:
	addq	$1, %r9
	addq	$120, %rdi
	addq	$8, %r10
	subq	$-128, %r8
.L2:
	movq	%r10, %rax
	movq	%rdi, %rdx
	testq	%r9, %r9
	jle	.L10
.L3:
	movq	(%rdx), %rcx
	movq	(%rax), %rsi
	movq	%rsi, (%rdx)
	movq	%rcx, (%rax)
	addq	$8, %rdx
	addq	$120, %rax
	cmpq	%r8, %rax
	jne	.L3
	addq	$1, %r9
	addq	$120, %rdi
	addq	$8, %r10
	subq	$-128, %r8
	cmpq	$15, %r9
	jne	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	transpose, .-transpose
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
