;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;      strpbrk.asm
;;      Thomas Graeff
;;      Holberton School
;;
;;      size_t asm_strpbrk(const char *s, const char *accept);
;;      - searches a string for a set of bytes
;;
;;      @rdi: string to be scanned
;;      @rsi: list of characters to match in 's'
;;
;;      Return: pointer to first occurence in 's' that is in 'accept'
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

    global asm_strpbrk

    section .text

asm_strpbrk:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor     rcx, rcx
    xor     rdx, rdx
    xor     r8, r8
    xor     r9, r9

    test    rdi, rdi
    jz      end
    test    rsi, rsi
    jz      end

RDI_LOOP:
    mov     r8b, BYTE [rdi + rcx]
    test    r8b, r8b        ;   check for end of string
    jz      end
    xor     rdx, rdx

RSI_LOOP:
    mov     r9b, BYTE [rsi + rdx]
    test    r9b, r9b        ;   no more characters to search for
    jz      strpbrk_NEXT

    cmp     r8b, r9b        ;   match found, set return value and end
    je      SET_RAX

    inc     rdx             ;   no match, check next character in 'accept'
    jmp     RSI_LOOP

strpbrk_NEXT:
    inc     rcx             ;   next character in list
    jmp     RDI_LOOP

SET_RAX:
    mov     rax, rdi
    add     rax, rcx

end:
    mov     rsp, rbp
    pop     rbp

    ret
