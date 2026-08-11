	.file	"funct1.c"
	.text
	.globl	funct1
	.type	funct1, @function
funct1:
.LFB0:
	.cfi_startproc
	endbr64
	vxorps	%xmm2, %xmm2, %xmm2
	vmovaps	%xmm0, %xmm3
	vcvtsi2ssq	%rsi, %xmm2, %xmm0
	vaddss	%xmm3, %xmm0, %xmm0
	vcvtsi2ssl	%edi, %xmm2, %xmm2
	vdivss	%xmm0, %xmm2, %xmm2
	vcvtss2sd	%xmm2, %xmm2, %xmm2
	vsubsd	%xmm1, %xmm2, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	funct1, .-funct1
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
