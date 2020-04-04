;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;      strcspn.asm
;;      Thomas Graeff
;;      Holberton School
;;
;;      size_t asm_strcspn(const char *s, const char *reject);
;;      - searches a string for a set of bytes that aren't in string
;;
;;      @rdi: string to be scanned
;;      @rsi: list of characters to match in 's'
;;
;;      Return: number of bytes in 's' that are not in 'reject'
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_strcspn

	section .text

asm_strcspn:
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
    jz      strcspn_NEXT

    cmp     r8b, r9b
    je      end             ;   no match found, loop to next position

    inc     rcx
    jmp     RSI_LOOP

strcspn_NEXT:
    inc     rax             ;   next character in main string
    jmp     RDI_LOOP

end:
    pop     r9
    pop     r8
    pop     rcx

    mov     rsp, rbp
    pop     rbp

    ret
