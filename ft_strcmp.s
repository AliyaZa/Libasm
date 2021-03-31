section .text
	global _ft_strcmp

_ft_strcmp:
	push r12
	push r13
	push rcx
	mov r12, rdi ;str1
	mov r13, rsi ;str2
	mov rcx, -1

.loop:
	inc rcx
	cmp BYTE [r12 + rcx], 0
	je .loop_end
	mov dl, BYTE [r12 + rcx]
	cmp dl, BYTE [r13 + rcx]
	je .loop

.loop_end:
	xor rax, rax
	mov al, BYTE[r12 + rcx]
	sub al, BYTE[r13 + rcx]
	jnc .return
	neg al
	neg eax

.return:
	pop rcx
	pop r13
	pop r12
	ret
