section .text
	global _ft_strcpy

_ft_strcpy:
	mov rcx, 0; i = 0

.loop:
	mov dl, BYTE [rsi + rcx]; dl = str[i]
	mov BYTE [rdi + rcx], dl ; dst[i] = dl
	cmp dl, 0
	je .return
	inc rcx
	jmp .loop

.return:
	mov rax, rdi
	ret
