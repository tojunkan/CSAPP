	.file	"branch.c"
	.text
	.globl	branch
	.type	branch, @function
branch:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	jmp	.L2
.L3:
	sarq	%rax
.L2:
	testq	%rax, %rax
	jg	.L3
	ret
	.cfi_endproc
.LFE0:
	.size	branch, .-branch
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
