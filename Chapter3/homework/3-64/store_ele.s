	.file	"store_ele.c"
	.text
	.globl	store_ele
	.type	store_ele, @function
store_ele:
.LFB0:
	.cfi_startproc
	endbr64
	leaq	(%rsi,%rsi,2), %rax
	leaq	(%rsi,%rax,4), %rax
	movq	%rdi, %rsi
	salq	$6, %rsi
	leaq	(%rsi,%rdi), %rsi
	addq	%rsi, %rax
	addq	%rdx, %rax
	leaq	A(%rip), %rdx
	movq	(%rdx,%rax,8), %rax
	movq	%rax, (%rcx)
	movl	$3640, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	store_ele, .-store_ele
	.globl	A
	.bss
	.align 32
	.type	A, @object
	.size	A, 3640
A:
	.zero	3640
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
