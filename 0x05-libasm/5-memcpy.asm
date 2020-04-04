;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;	memcpy.asm
;;	Thomas Graeff
;;	Holberton School
;;
;;  void *asm_memcpy(void *dest, const void *src, size_t n);
;;  - copy memory area from source to destination
;;
;;  @rdi: dest
;;  @rsi: src
;;  @rdx: n
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

BITS 64

	global asm_memcpy

	section .text

asm_memcpy:
	push    rbp
	mov     rbp, rsp
    xor     rax, rax
    push    rdi

memcpy_loop:
    test    rdx, rdx
    jz      end
    mov     al, BYTE [rsi]   ; put byte of SRC into AL
    inc     rsi
    mov BYTE [rdi], al       ; put byte of AL into DEST
    inc     rdi
    dec     rdx
    jmp     memcpy_loop

end:
    pop     rax
    mov     rsp, rbp
    pop     rbp

    ret
