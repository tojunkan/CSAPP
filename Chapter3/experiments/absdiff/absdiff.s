	.file	"absdiff.c"
	.text
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB0:
	.cfi_startproc
	endbr64
	cmpl	%esi, %edi
	jge	.L2
	movl	%esi, %eax
	subl	%edi, %eax
	ret
.L2:
	movl	%edi, %eax
	subl	%esi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	absdiff, .-absdiff
	.globl	gotodiff
	.type	gotodiff, @function
gotodiff:
.LFB1:
	.cfi_startproc
	endbr64
	cmpl	%esi, %edi
	jl	.L5
	movl	%edi, %eax
	subl	%esi, %eax
	ret
.L5:
	movl	%esi, %eax
	subl	%edi, %eax
.L6:
	ret
	.cfi_endproc
.LFE1:
	.size	gotodiff, .-gotodiff
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
