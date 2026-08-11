	.file	"var_prod_ele_opt.c"
	.text
	.globl	var_prod_ele_opt
	.type	var_prod_ele_opt, @function
var_prod_ele_opt:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %r9
	imulq	%rdi, %rcx
	leaq	(%rdx,%r8,4), %rdi
	movl	$0, %eax
	movl	$0, %r8d
	jmp	.L2
.L3:
	leaq	(%rcx,%rax), %r10
	movl	(%rdi), %edx
	imull	(%rsi,%r10,4), %edx
	addl	%edx, %r8d
	leaq	(%rdi,%r9,4), %rdi
	addq	$1, %rax
.L2:
	cmpq	%r9, %rax
	jl	.L3
	movl	%r8d, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	var_prod_ele_opt, .-var_prod_ele_opt
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
