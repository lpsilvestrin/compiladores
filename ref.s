	.data
x:
	.long	42
y:
	.long	36
z:
	.long	0
	.section	.rodata
.LC0:
	.string	"test"
.LC1:
	.string	"%s"
.LC2:
	.string	"%d"
	.globl	main
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	movq	%rsp, %rbp
	movq	$.LC0, %rsi
	movl	$.LC1, %edi
	call	printf
	movq	y(%rip), %rsi
	movl	$.LC2, %edi
	call	printf
	
	leave
	ret
	.cfi_endproc
