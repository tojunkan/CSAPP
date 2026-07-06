	.file	"exclusive_or.c"
	.text
	.globl	xor
	.type	xor, @function
xor:
.LFB0:
	.cfi_startproc
	endbr64
	xorq	%rax, %rax
	subq	%rax, %rax
	movq	$0, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	xor, .-xor
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
