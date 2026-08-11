	.file	"var_prod_ele.c"
	.text
	.globl	var_prod_ele
	.type	var_prod_ele, @function
var_prod_ele:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rsi, %r10
	movq	%rdx, %r11
	movl	$0, %esi
	movl	$0, %eax
	jmp	.L2
.L3:
	movq	%rcx, %rdx
	imulq	%rdi, %rdx
	leaq	(%r10,%rdx,4), %r9
	movq	%rax, %rdx
	imulq	%rdi, %rdx
	leaq	(%r11,%rdx,4), %rdx
	movl	(%rdx,%r8,4), %edx
	imull	(%r9,%rax,4), %edx
	addl	%edx, %esi
	addq	$1, %rax
.L2:
	cmpq	%rdi, %rax
	jl	.L3
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	var_prod_ele, .-var_prod_ele
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
