	.file	"vframe.c"
	.text
	.globl	vframe
	.type	vframe, @function
vframe:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, %rcx
	movq	%rsi, %rdi
	leaq	15(,%rcx,8), %rax
	movq	%rax, %r8
	andq	$-16, %r8
	andq	$-4096, %rax
	movq	%rsp, %rsi
	subq	%rax, %rsi
.L2:
	cmpq	%rsi, %rsp
	je	.L3
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L2
.L3:
	movq	%r8, %rax
	andl	$4095, %eax
	subq	%rax, %rsp
	testq	%rax, %rax
	je	.L4
	orq	$0, -8(%rsp,%rax)
.L4:
	leaq	7(%rsp), %rsi
	movq	%rsi, %rax
	shrq	$3, %rax
	andq	$-8, %rsi
	leaq	-8(%rbp), %r8
	movq	%r8, 0(,%rax,8)
	movq	$1, -8(%rbp)
	cmpq	$1, %rcx
	jle	.L5
	movl	$1, %eax
.L6:
	movq	%rdx, (%rsi,%rax,8)
	addq	$1, %rax
	cmpq	%rax, %rcx
	jne	.L6
	movq	%rcx, -8(%rbp)
.L5:
	movq	(%rsi,%rdi,8), %rax
	movq	(%rax), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	vframe, .-vframe
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
