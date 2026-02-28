	.file	"mstore.c"
	.intel_syntax noprefix
	.text
	.globl	multstore
	.type	multstore, @function
multstore:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbx			# the intel code omits the '%'character in front of rigister names. we see rbx instead of %rbx.
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdx		# the intel code omits the size designation suffixes. we see mov instead of movq.
	call	mult2@PLT
	mov	QWORD PTR [rbx], rax	# the intel code has a different way of describing locations in memory, for example 'QWORD PTR [rbx]' instead of (%rbx).
					#also, instructions with multiple operands list them in the reverse order!!!
	pop	rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	multstore, .-multstore
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
