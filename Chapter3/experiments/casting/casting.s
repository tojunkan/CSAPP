	.file	"casting.c"
	.text
	.globl	long2long
	.type	long2long, @function
long2long:
.LFB0:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	movq	%rax, (%rsi)
	ret
	.cfi_endproc
.LFE0:
	.size	long2long, .-long2long
	.globl	char2int
	.type	char2int, @function
char2int:
.LFB1:
	.cfi_startproc
	endbr64
	movsbl	(%rdi), %eax
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE1:
	.size	char2int, .-char2int
	.globl	char2unsigned
	.type	char2unsigned, @function
char2unsigned:
.LFB2:
	.cfi_startproc
	endbr64
	movsbl	(%rdi), %eax
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE2:
	.size	char2unsigned, .-char2unsigned
	.globl	unsigned_char2long
	.type	unsigned_char2long, @function
unsigned_char2long:
.LFB3:
	.cfi_startproc
	endbr64
	movzbl	(%rdi), %eax
	movq	%rax, (%rsi)
	ret
	.cfi_endproc
.LFE3:
	.size	unsigned_char2long, .-unsigned_char2long
	.globl	int2char
	.type	int2char, @function
int2char:
.LFB4:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	movb	%al, (%rsi)
	ret
	.cfi_endproc
.LFE4:
	.size	int2char, .-int2char
	.globl	unsigned2unsigned_char
	.type	unsigned2unsigned_char, @function
unsigned2unsigned_char:
.LFB5:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	movb	%al, (%rsi)
	ret
	.cfi_endproc
.LFE5:
	.size	unsigned2unsigned_char, .-unsigned2unsigned_char
	.globl	char2short
	.type	char2short, @function
char2short:
.LFB6:
	.cfi_startproc
	endbr64
	movsbw	(%rdi), %ax
	movw	%ax, (%rsi)
	ret
	.cfi_endproc
.LFE6:
	.size	char2short, .-char2short
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
