;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;	strcmp.asm
;;	Thomas Graeff
;;	Holberton School
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_strcmp

	section .text

asm_strcmp:
    push    rbp
    mov     rbp, rsi

    xor     eax, eax
    xor     rcx, rcx

strcmp_loop:
    mov     dl, BYTE [rdi + rcx]
    mov     dh, BYTE [rsi + rcx]
    inc     rcx
    test    dl, dl
    je      check_s1	; check if s1 is NULL
    test    dh, dh
    je      strcmp_above
    cmp     dl, dh
    je      strcmp_loop
    jmp     strcmp_compare

check_s1:
    test    dh, dh
    je      strcmp_end
    jmp     strcmp_below

strcmp_compare:
    cmp     dl, dh
    jl      strcmp_below
    jg      strcmp_above

strcmp_above:
    xor     dl, dh	; s1 bigger than s2
    inc     eax
    jmp     strcmp_end

strcmp_below:
    xor     dl, dh  ; s1 smaller than s2
    dec     eax
    jmp     strcmp_end

strcmp_end:
    mov     rsi, rbp
    pop     rbp
    ret
