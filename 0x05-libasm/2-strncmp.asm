;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;      strncmp.asm
;;      Thomas Graeff
;;      Holberton School
;;
;;      int asm_strncmp(const char *s1, const char *s2, size_t n);
;;      - compares s1 and s2 up to n bytes
;;
;;      @rdi: s1
;;      @rsi: s2
;;      @rdx: n
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

    global asm_strncmp

    section .text

asm_strncmp:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx

STRNCMP_LOOP:
    cmp     rcx, rdx
    je      STRNCMP_COMPARE

    mov     al, [rdi + rcx]
    mov     bl, [rsi + rcx]

    test    al, al
    jz      STRNCMP_COMPARE
    test    bl, bl
    jz      STRNCMP_COMPARE

    cmp     al, bl
    jne     STRNCMP_COMPARE

    inc     rcx
    jmp     STRNCMP_LOOP

STRNCMP_COMPARE:
    cmp     al, bl
    jl      STRNCMP_BELOW
    jg      STRNCMP_ABOVE
    je      STRNCMP_EQUAL

STRNCMP_ABOVE:
    mov     rax, 1
    jmp     end

STRNCMP_BELOW:
    mov     rax, -1
    jmp     end

STRNCMP_EQUAL:
    mov     rax, 0

end:
    pop     rcx
    mov     rsp, rbp
    pop     rbp
    ret
