.LC0:
    .string "test"
.LC1:
    .string "%s"
.LC2:
    .string "%d"
// define variables
    .data
x:
    .long   42
y:
    .long   36
_z:
    .long   0
// function declaration
foo:
    .cfi_startproc
    pushq   %rbp
    movq    %rsp, %rbp
    // function body
    popq    %rbp
    ret
    .cfi_endproc

    .globl  main
main:
    .cfi_startproc
    pushq   %rbp
    movq    %rsp, %rbp
    movq    $.LC0, %rsi
    movl    $.LC1, %edi
    call    printf

//printf
// variable "label" access: label(%rip)
    movl    $0, %eax
    addl    x(%rip), %eax 
    addl    y(%rip), %eax
    movl    %eax, _z(%rip)
    movq    _z(%rip), %rsi
    movl    $.LC2, %edi
    call    printf
    popq    %rbp
    ret
    .cfi_endproc
