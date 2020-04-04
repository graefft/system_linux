;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;	puts.asm
;;	Thomas Graeff
;;	Holberton School
;;
;;  size_t asm_puts(const char *str);
;;  -writes the string to stream
;;
;;  @rsi: str
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_puts

    extern asm_strlen

	section .text

asm_puts:
    push    rbp
    mov     rbp, rsp

    push    rdi
    call    asm_strlen
    pop     rdi

    push    rdi
    push    rsi
    mov     rdx, rax    ;   length to rdx
    mov     rax, 1      ;   write syscall
    mov     rsi, rdi    ;   address of buf
    mov     rdi, 1      ;   stdout fd
    syscall

end:
    pop     rsi
    pop     rdi
    mov     rsp, rbp
    pop     rbp
    ret
