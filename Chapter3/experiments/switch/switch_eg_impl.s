	.file	"switch_eg_impl.c"
	.text
	.globl	switch_eg_impl
	.type	switch_eg_impl, @function
switch_eg_impl:
.LFB0:
	.cfi_startproc
	endbr64
	subq	$100, %rsi
	cmpq	$6, %rsi
	ja	.L2
	leaq	jt.0(%rip), %rax
	jmp	*(%rax,%rsi,8)
.L3:
	endbr64
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
	jmp	.L4
.L5:
	endbr64
	addq	$10, %rdi
.L6:
	endbr64
	addq	$11, %rdi
	jmp	.L4
.L7:
	endbr64
	imulq	%rdi, %rdi
	jmp	.L4
.L2:
	endbr64
	movl	$0, %edi
.L4:
	movq	%rdi, (%rdx)
	ret
	.cfi_endproc
.LFE0:
	.size	switch_eg_impl, .-switch_eg_impl
	.section	.data.rel.ro.local,"aw"
	.align 32						;Align address to multiple of 32
	.type	jt.0, @object
	.size	jt.0, 56
jt.0:
	.quad	.L3						;quad means quad word, which is 8 bytes.
	.quad	.L2
	.quad	.L5
	.quad	.L6
	.quad	.L7
	.quad	.L2
	.quad	.L7
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
