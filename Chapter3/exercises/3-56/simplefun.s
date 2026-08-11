	.file	"simplefun.c"
	.text
	.p2align 4
	.globl	simplefun1
	.type	simplefun1, @function
simplefun1:
.LFB0:
	.cfi_startproc
	endbr64
	vandpd	.LC0(%rip), %xmm0, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	simplefun1, .-simplefun1
	.p2align 4
	.globl	simplefun2
	.type	simplefun2, @function
simplefun2:
.LFB1:
	.cfi_startproc
	endbr64
	vxorpd	%xmm0, %xmm0, %xmm0
	ret
	.cfi_endproc
.LFE1:
	.size	simplefun2, .-simplefun2
	.p2align 4
	.globl	simplefun3
	.type	simplefun3, @function
simplefun3:
.LFB2:
	.cfi_startproc
	endbr64
	vxorpd	.LC2(%rip), %xmm0, %xmm0
	ret
	.cfi_endproc
.LFE2:
	.size	simplefun3, .-simplefun3
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	-1
	.long	2147483647
	.long	0
	.long	0
	.align 16
.LC2:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
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
