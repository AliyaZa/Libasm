section .text
	global _ft_list_size

_ft_list_size:
	xor rax, rax
	cmp rdi, 0
	jz end

inc:
	mov	rdi, [rdi + 8]
	inc rax

cmp:
	cmp rdi, 0
	jne inc
	je end

end:
	ret
