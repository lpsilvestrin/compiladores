	.data
._print_int:
	.string "%d"
._print_string:
	.string "%s"
._print_float:
	.string "%f"
._print_char:
	.string "%c"
._0:
	.long 0
._1:
	.long 1
._2:
	.long 2
._3:
	.long 3
._temp0:
	.long 0
._temp1:
	.long 0
._temp2:
	.long 0
	.comm	.vec1,24,24
	.comm	.vec2,24,24
	.comm	.vec3,24,24
	pushq	%rbp
	movl	$1, .vec1+0(%rip)
	movl	$1, .vec1+8(%rip)
	movl	$1, .vec1+16(%rip)
	popq	%rbp

._4:
	.long	0
	.globl increment
increment:
	.cfi_startproc
	pushq	%rbp
	movq	%rsp, %rbp
	movl	16(%rbp), %edx
	movl	._1(%rip), %eax
	addl	%edx, %eax
	movl	%eax, ._temp2(%rip)
	movl	._temp2(%rip), %edx
	popq	%rbp
	ret
	.cfi_endproc
	.globl main
main:
	.cfi_startproc
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$2, .vec1+8(%rip)
	movl	$3, .vec1+0(%rip)
	movl	._2(%rip), %eax
	cltq
	movl	.vec1(,%rax,8), %edi
	movl	%edi, ._temp1(%rip)
	movq	._temp1(%rip), %rsi
	movl	$._print_int, %edi
	call	printf
	movl	$0, .vec1+16(%rip)
	movl	._2(%rip), %eax
	cltq
	movl	.vec1(,%rax,8), %edi
	movl	%edi, ._temp0(%rip)
	movq	._temp0(%rip), %rsi
	movl	$._print_int, %edi
	call	printf
	popq	%rbp
	ret
	.cfi_endproc
