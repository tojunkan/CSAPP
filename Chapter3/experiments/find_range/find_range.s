	.file	"find_range.c"
	.text
	.globl	find_range
	.type	find_range, @function
find_range:
.LFB0:
	.cfi_startproc
	endbr64
	vxorps	%xmm1, %xmm1, %xmm1
	vcomiss	%xmm0, %xmm1
	ja	.L5
	vucomiss	%xmm1, %xmm0
	jp	.L8
	jne	.L8
	movl	$1, %eax
	ret
.L8:
	vxorps	%xmm1, %xmm1, %xmm1
	vcomiss	%xmm1, %xmm0
	jbe	.L10
	movl	$2, %eax
	ret
.L5:
	movl	$0, %eax
	ret
.L10:
	movl	$3, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	find_range, .-find_range
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
