;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;      strstr.asm
;;	    Thomas Graeff
;;	    Holberton School
;;
;;      char *asm_strstr(const char *haystack, const char *needle);
;;      - locates substring 'needle' in string 'haystack'
;;
;;      @rdi: haystack
;;      @rsi: needle
;;
;;      Return: first occurrence of substring ('needle') in 'haystack'
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_strstr

	section .text

asm_strstr:
	push    rbp
	mov     rbp, rsp

    push    rcx
    push    r8
    push    r9
    xor     rax, rax
    xor     rcx, rcx
    xor     r8, r8
    xor     r9, r9

    cmp     [rsi], byte 0   ;   if no needle
    je      strstr_COMPARE
    cmp     [rdi], byte 0   ;   if no haystack
    je      end

strstr_LOOP:
    movzx   r8, BYTE [rdi + rcx]
    movzx   r9, BYTE [rsi + rcx]

    cmp     r8b, byte 0
    je      strstr_COMPARE
    cmp     r9b, byte 0
    je      strstr_COMPARE

    cmp     r8, r9          ;   if same then loop to next position
    je      strstr_NEXT

    inc     rdi             ;   iterate through 'haystack'
    xor     rcx, rcx
    jmp     strstr_LOOP

strstr_NEXT:
    inc     rcx
    jmp     strstr_LOOP

strstr_COMPARE:
    test    r9b, r9b
    jnz     end

    mov     rax, rdi        ;   set RETURN

end:
    pop     r9
    pop     r8
    pop     rcx

    mov     rsp, rbp
    pop     rbp

    ret
