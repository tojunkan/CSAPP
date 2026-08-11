	.file	"sum_col.c"
	.text
	.globl	sum_col
	.type	sum_col, @function
sum_col:
.LFB0:
	.cfi_startproc
	endbr64
	leaq	1(,%rdi,4), %r8
	testq	%rdi, %rdi
	jle	.L4
	salq	$3, %r8
	leaq	(%rsi,%rdx,8), %rdx
	leaq	(%rdi,%rdi,2), %rsi
	movl	$0, %ecx
	movl	$0, %eax
.L3:
	addq	(%rdx), %rcx
	addq	$1, %rax
	addq	%r8, %rdx
	cmpq	%rsi, %rax
	jne	.L3
.L1:
	movq	%rcx, %rax
	ret
.L4:
	movl	$0, %ecx
	jmp	.L1
	.cfi_endproc
.LFE0:
	.size	sum_col, .-sum_col
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
