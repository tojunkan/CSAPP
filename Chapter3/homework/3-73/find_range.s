	.file	"find_range.c"
	.text
	.globl	find_range
	.type	find_range, @function
find_range:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -20(%rbp)
	movsd	-8(%rbp), %xmm0
	movss	-20(%rbp), %xmm1
#APP
# 10 "find_range.c" 1
	vxorps %xmm0, %xmm0, %xmm0
	vucomiss %xmm0, %xmm1
	jp 3f
	ja 0f
	je 1f
	jb 2f
	0:
	movl $0, %eax
	jmp 4f
	1:
	movl $1, %eax
	jmp 4f
	2:
	movl $2, %eax
	jmp 4f
	3:
	movl $3, %eax
	jmp 4f
	4:
	
# 0 "" 2
#NO_APP
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	find_range, .-find_range
	.section	.rodata
.LC0:
	.string	"%f"
.LC1:
	.string	"positive."
.LC2:
	.string	"zero."
.LC3:
	.string	"negative."
.LC4:
	.string	"not a number."
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-16(%rbp), %eax
	movd	%eax, %xmm0
	call	find_range
	movl	%eax, -12(%rbp)
	cmpl	$3, -12(%rbp)
	je	.L4
	cmpl	$3, -12(%rbp)
	ja	.L5
	cmpl	$2, -12(%rbp)
	je	.L6
	cmpl	$2, -12(%rbp)
	ja	.L5
	cmpl	$0, -12(%rbp)
	je	.L7
	cmpl	$1, -12(%rbp)
	je	.L8
	jmp	.L5
.L7:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L5
.L8:
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L5
.L6:
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L5
.L4:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
.L5:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
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
