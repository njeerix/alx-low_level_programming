SECTION .data
   hello db "Hello, Holberton", 0
   format db "%s\n", 0

SECTION .text
   extern printf
   global main

main:
    push rbp
    mov rdi, format
    mov rsi, hello
    xor rax, rax
    call printf
    pop rbp
    ret
