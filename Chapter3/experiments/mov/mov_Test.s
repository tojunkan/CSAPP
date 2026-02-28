.global main
main:
	movb $0xF, (%rbx)
	movq %rax, (%rsp)
	movw (%rax), %sp	# or movw %ax, 4(%sp)
	movb %al, %sil
	movq $0x123, %rax
	movl %eax, %edx		#both operands should match the suffix
	movb %sil, 8(%rbp)

# movb $0xF, (%bx)	Error: `(%bx)' is not a valid base/index expression
# movb %rax, (%rsp) 	Error: incorrect register `%rax' used with `l' suffix
# movw (%rax), 4(%rsp)  Error: operand size mismatch for `mov'
# movb %al, %sl		Error: bad register name `%sl'
# movq %rax, $0x123	Error: operand type mismatch for `movq'
# movl %eax, %rdx 	Error: operand type mismatch for `mov'
# movb %si, 8(%rbp) 	Error: `%si' not allowed with `movb'
