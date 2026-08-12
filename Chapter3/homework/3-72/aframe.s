	.file	"aframe.c"
	.text
	.globl	aframe
	.type	aframe, @function
aframe:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rsi, %r8
	movq	%rdx, %rcx
	leaq	0(,%rdi,8), %rdx
	leaq	23(%rdx), %rax
	movq	%rax, %r9
	andq	$-16, %r9
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
	movq	%r9, %rax
	andl	$4095, %eax
	subq	%rax, %rsp
	testq	%rax, %rax
	je	.L4
	orq	$0, -8(%rsp,%rax)
.L4:
	leaq	15(%rsp), %rsi
	andq	$-16, %rsi
	leaq	-8(%rbp), %rax
	movq	%rax, (%rsi)
	movq	$1, -8(%rbp)
	cmpq	$1, %rdi
	jle	.L5
	leaq	8(%rsi), %rax
	addq	%rsi, %rdx
.L6:
	movq	%rcx, (%rax)
	addq	$8, %rax
	cmpq	%rdx, %rax
	jne	.L6
	movq	%rdi, -8(%rbp)
.L5:
	movq	(%rsi,%r8,8), %rax
	movq	(%rax), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	aframe, .-aframe
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
