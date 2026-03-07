	.file	"decode2.c"
	.text
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB0:
	.cfi_startproc
	endbr64
	subq	%rdx, %rsi
	imulq	%rsi, %rdi
	salq	$63, %rsi
	sarq	$63, %rsi
	movq	%rdi, %rax
	xorq	%rsi, %rax
	ret
# it can also be written like this:
#	  subq    %rdx, %rsi
#	  imulq   %rsi, %rdi
#	  movq    %rsi, %rax
#	  salq    $63, %rax
#	  sarq    $63, %rax
#	  xorq    %rdi, %rax
	.cfi_endproc
.LFE0:
	.size	decode2, .-decode2
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
