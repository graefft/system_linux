;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;      strchr.asm
;;      Thomas Graeff
;;      Holberton School
;;
;;      char *asm_strchr(const char *s, int c);
;;      - locates character in string
;;
;;      @rdi: *s -- string to search in
;;      @rsi:  c -- character to search for
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

    global asm_strchr

    section .text

asm_strchr:
    push    rbp
    mov     rbp, rsp
    xor     rax, rax

strchr_loop:
    mov     al, BYTE [rdi]
    cmp     BYTE [rdi], sil ; compare with character to search
    jz      strchr_match    ; match found
    cmp     BYTE [rdi], 0   ; check if string is NULL yet
    jz      end             ; reached end of string
    inc     rdi             ; next character in string
    jmp     strchr_loop

strchr_match:
    mov     rax, rdi        ; return pointer to first occurence of 'c'

end:
    mov rsp, rbp
    pop rbp

    ret
