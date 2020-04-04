;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;	putc.asm
;;	Thomas Graeff
;;	Holberton School
;;
;;  size_t asm_putc(int c);
;;  -writes the character 'c' to stream
;;
;;  @rsi: c
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_putc

	section .text

asm_putc:
	push    rbp
	mov     rbp, rsp
    push    rdi

    mov     rax, 1      ;   return value
    mov     rdx, 1
    mov     rdi, 1      ;   stdout fd
    mov     rsi, rsp    ;   move stack pointer to 'c'
    syscall

end:
    pop     rdi
    mov     rsp, rbp
    pop     rbp
    ret
