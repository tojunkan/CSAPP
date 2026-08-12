	.file	"eval.c"
	.text
	.globl	process
	.type	process, @function
process:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	movq	16(%rsp), %rdx
	movq	%rdx, -40(%rsp)
	movq	8(%rsp), %rdx
	movq	%rdx, -32(%rsp)
	movq	24(%rsp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -24(%rsp)
	movdqa	-40(%rsp), %xmm0
	movups	%xmm0, (%rdi)
	movq	%rdx, 16(%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	process, .-process
	.globl	eval
	.type	eval, @function
eval:
.LFB1:
	.cfi_startproc
	endbr64
	subq	$88, %rsp
	.cfi_def_cfa_offset 96
	movq	%rdx, 8(%rsp)
#	store varialbe z (because struct strA only store its address, not value.)
	movq	%rdi, 48(%rsp)
	movq	%rsi, 56(%rsp)
	leaq	8(%rsp), %rax
	movq	%rax, 64(%rsp)
#	store struct strA s, from +48 ~ +71 (total 24 bytes)
	leaq	16(%rsp), %rdi
#	here assigned an address to %rdi, and %rdi is where process() places calculated struct values in.
	subq	$32, %rsp
#	extend stack frame so that totally gets 120 bytes.
	.cfi_def_cfa_offset 128
	movdqa	80(%rsp), %xmm0
#	this is SSE instruction, using wider registers to make copies more effecient.
#	d refers to double, q refers to quadword, a refers to aligned.
#	this instruction reads whole 128 bits from memory to %xmm0
#	here means copy the struct strA s to xmm0.
	movups	%xmm0, (%rsp)
#	this instruction writes whole 128 bits,
#	where u is unaligned, p refers packed, s refers to single-percision.
#	here means move the copied struct variable to where rsp points.
	movq	%rax, 16(%rsp)
	call	process
	movq	56(%rsp), %rax
	addq	48(%rsp), %rax
	addq	64(%rsp), %rax
#	add up all values to get result.
	addq	$120, %rsp
#	free all spaces.

#	you can see that, when it comes to struct arguments in functions,
#	a universal way is that callers allocate space, and callees fill values into it.
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	eval, .-eval
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
