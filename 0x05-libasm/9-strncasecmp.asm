;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;	    strncasecmp.asm
;;	    Thomas Graeff
;;	    Holberton School
;;
;;      int asm_strncasecmp(const char *s1, const char *s2, size_t n);
;;      -compare two strings up to 'n' bytes ignoring case
;;
;;      @rdi: s1
;;      @rsi: s2
;;      @rdx: n
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_strncasecmp

	section .text

asm_strncasecmp:
    push    rbp
    mov     rbp, rsp

    push    r8
    push    r9
    push    rcx

    xor     r8, r8
    xor     r9, r9
    xor     rcx, rcx

strncase_LOOP:
    cmp     rcx, rdx
    je      EQUAL

    mov     r8b, BYTE [rdi + rcx]
    mov     r9b, BYTE [rsi + rcx]

    test    r8b, r8b
    je      end
    test    r9b, r9b
    je      end

strncase_S1:
    cmp     r8b, 65         ;   checks if char is < 'A' (lowercase)
    jb      strncase_S2
    cmp     r8b, 90         ;   checks if char is > 'Z' (lowercase)
    jg      strncase_S2

    add     r8b, 32         ;   convert to lowercase

strncase_S2:
    cmp     r9b, 65
    jb      strncase_NEXT
    cmp     r9b, 90
    jg      strncase_NEXT

    add     r9b, 32         ;   convert to lowercase

strncase_NEXT:
    inc     rcx

    cmp     r8b, r9b        ;   (s1 != s2)
    jne     SUB

    cmp     r8b, 0          ;   (!s1)
    je      EQUAL

    jmp     strncase_LOOP

EQUAL:
    mov     rax, 0x0
    jmp     end

SUB:
    mov     rax, r8
    sub     rax, r9

end:
    pop     rcx
    pop     r9
    pop     r8

    mov     rsp, rbp
    pop     rbp
    ret
