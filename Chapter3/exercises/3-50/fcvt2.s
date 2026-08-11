	.file	"fcvt2.c"
	.text
	.globl	fcvt2
	.type	fcvt2, @function
fcvt2:
.LFB0:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	movss	(%rsi), %xmm0
	cvttsd2sil	(%rdx), %r8d
	movl	%r8d, (%rdi)
	pxor	%xmm1, %xmm1
	cvtsi2ssl	%eax, %xmm1
	movss	%xmm1, (%rsi)
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rcx, %xmm1
	movsd	%xmm1, (%rdx)
	cvtss2sd	%xmm0, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	fcvt2, .-fcvt2
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
