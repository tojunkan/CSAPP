	.file	"silly.c"
	.text
	.globl	silly
	.type	silly, @function
silly:
.LFB0:
	.cfi_startproc
	endbr64
	movl	%edx, %eax
	testl	%edx, %edx
	jg	.L3
	ret
.L4:
	movl	%eax, %edx
	sarl	%edx
	subl	%edx, %eax
	leal	(%rax,%rax,2), %eax
.L3:
	testl	%eax, %eax
	jg	.L4
	ret
	.cfi_endproc
.LFE0:
	.size	silly, .-silly
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
