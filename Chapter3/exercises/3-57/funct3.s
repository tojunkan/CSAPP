	.file	"funct3.c"
	.text
	.globl	funct3
	.type	funct3, @function
funct3:
.LFB0:
	.cfi_startproc
	endbr64
	vxorps	%xmm1, %xmm1, %xmm1
	vmovsd	%xmm0, %xmm0, %xmm3
	vmovss	(%rdx), %xmm2
	vcvtsi2sdl	(%rdi), %xmm1, %xmm0
	vcomisd	%xmm0, %xmm3
	ja	.L7
	vaddss	%xmm2, %xmm2, %xmm2
	vcvtsi2ssq	%rsi, %xmm1, %xmm0
	vaddss	%xmm2, %xmm0, %xmm0
	vcvtss2sd	%xmm0, %xmm0, %xmm0
	ret
.L7:
	vcvtsi2ssq	%rsi, %xmm1, %xmm0
	vmulss	%xmm2, %xmm0, %xmm0
	vcvtss2sd	%xmm0, %xmm0, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	funct3, .-funct3
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
