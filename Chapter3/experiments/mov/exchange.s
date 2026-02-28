	.file	"exchange.c"
	.text
	.globl	exchange
	.type	exchange, @function

# long exchange(long *xp, long y)
# {
#	  long x = *xp;
#	  *xp = y;
#	  return x;
# }
exchange:
.LFB0:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax	#%rdi refers to the first argument(xp), and () means treating it as a pointer. also, $rax stores the first variable, and set as return value.
	movq	%rsi, (%rdi)	#%rsi refers to the second argument.
	ret			#when return the function will yeild %rax
	.cfi_endproc
.LFE0:
	.size	exchange, .-exchange
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
