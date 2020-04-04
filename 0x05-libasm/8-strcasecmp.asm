;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;	    strcasecmp.asm
;;	    Thomas Graeff
;;	    Holberton School
;;
;;      int asm_strcasecmp(const char *s1, const char *s2);
;;      -compare two strings ignoring case
;;
;;      @rdi: s1
;;      @rsi: s2
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_strcasecmp

    extern asm_strlen

	section .text

asm_strcasecmp:
    push    rbp
    mov     rbp, rsp

    push    r8
    push    r9

    xor     r8, r8
    xor     r9, r9

strcase_LOOP:
    mov     r8b, [rdi]
    mov     r9b, [rsi]
    inc     rdi
    inc     rsi

strcase_S1:
    cmp     r8b, 65         ;   checks if char is < 'A' (lowercase)
    jl      strcase_NEXT
    cmp     r8b, 90         ;   checks if char is > 'Z' (lowercase)
    jg      strcase_NEXT

    add     r8b, 32         ;   convert to lowercase

strcase_S2:
    cmp     r9b, 65
    jl      strcase_NEXT
    cmp     r9b, 90
    jl      strcase_NEXT

    add     r9b, 32         ;   convert to lowercase

strcase_NEXT:
    test    r8b, r8b        ;   check if 'str1' is NULL
    je      end
    test    r9b, r9b        ;   check if 'str2' is NULL
    je      end

    inc     rcx
    cmp     r8b, r9b
    je      strcase_LOOP

end:
    pop     r9
    pop     r8

    mov     rsp, rbp
    pop     rbp
    ret
