;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;      strspn.asm
;;      Thomas Graeff
;;      Holberton School
;;
;;      size_t asm_strspn(const char *s, const char *accept);
;;      - searches a string for a set of bytes
;;
;;      @rdi: string to be scanned
;;      @rsi: list of characters to match in 's'
;;
;;      Return: number of bytes in 's' that consist of characters
;;              from 'accept'
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

    global asm_strspn

    section .text

asm_strspn:
    push    rbp
    mov     rbp, rsp

    push    rcx
    push    r8
    push    r9

    xor     rax, rax
    xor     rcx, rcx
    xor     r8, r8
    xor     r9, r9

RDI_LOOP:
    mov     r8b, BYTE [rdi + rax]
    test    r8b, r8b        ;   check for end of string
    jz      end

    xor     rcx, rcx        ;   start RSI at 0

RSI_LOOP:
    mov     r9b, BYTE [rsi + rcx]
    test    r9b, r9b        ;   no more characters to search for
    jz      end

    cmp     r8b, r9b        ;   match found, loop to next position in string
    je      strspn_NEXT

    inc     rcx             ;   next character in list
    jmp     RSI_LOOP

strspn_NEXT:
    inc     rax             ;   next character in main string
    jmp     RDI_LOOP

end:
    pop     r9
    pop     r8
    pop     rcx

    mov     rsp, rbp
    pop     rbp

    ret
