	.file	"get.c"
	.text
	.globl	get_long
	.type	get_long, @function
get_long:
.LFB0:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	movq	%rax, (%rsi)
	ret
	.cfi_endproc
.LFE0:
	.size	get_long, .-get_long
	.globl	get_short
	.type	get_short, @function
get_short:
.LFB1:
	.cfi_startproc
	endbr64
	movzwl	8(%rdi), %eax
	movw	%ax, (%rsi)
	ret
	.cfi_endproc
.LFE1:
	.size	get_short, .-get_short
	.globl	get_charp
	.type	get_charp, @function
get_charp:
.LFB2:
	.cfi_startproc
	endbr64
	addq	$10, %rdi
	movq	%rdi, (%rsi)
	ret
	.cfi_endproc
.LFE2:
	.size	get_charp, .-get_charp
	.globl	get_intp
	.type	get_intp, @function
get_intp:
.LFB3:
	.cfi_startproc
	endbr64
	movq	%rdi, (%rsi)
	ret
	.cfi_endproc
.LFE3:
	.size	get_intp, .-get_intp
	.globl	get_int
	.type	get_int, @function
get_int:
.LFB4:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	movl	(%rdi,%rax,4), %eax
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE4:
	.size	get_int, .-get_int
	.globl	get_char
	.type	get_char, @function
get_char:
.LFB5:
	.cfi_startproc
	endbr64
	movq	8(%rdi), %rax
	movzbl	(%rax), %eax
	movb	%al, (%rsi)
	ret
	.cfi_endproc
.LFE5:
	.size	get_char, .-get_char
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
