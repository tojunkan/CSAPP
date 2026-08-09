	.file	"swap_add.c"
	.text
	.globl	swap_add
	.type	swap_add, @function
swap_add:
.LFB0:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	movq	(%rsi), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, (%rsi)
	addq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	swap_add, .-swap_add
	.globl	caller
	.type	caller, @function
caller:
.LFB1:
	.cfi_startproc
	endbr64
	subq	$16, %rsp
	.cfi_def_cfa_offset 24
	movq	$534, 8(%rsp)
	movq	$1057, (%rsp)
	movq	%rsp, %rsi
	leaq	8(%rsp), %rdi
	call	swap_add
	movq	8(%rsp), %rdx
	subq	(%rsp), %rdx
	imulq	%rdx, %rax
	addq	$16, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	caller, .-caller
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
