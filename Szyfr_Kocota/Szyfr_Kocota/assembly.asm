.CODE

asm_encrypt PROC; char* loaded_text, char* shuffled_alphabet_tab, int index 

	push rbx
	push rcx
	push rdx ;dla bezpieczenstwa zapamietujemy rejestry

	add rcx, r8 ;inkrementacja wskaznika o indeks
	mov sil, [rcx] ;przeniesienie szukanej litery do rejestru sil
	mov r10, 0 ;wpisanie do r10 licznika petli

main_loop:
	cmp sil, [rdx] ;porownanie szukanej litery do litery z alfaberu
	je found ;jesli znaleziono
	cmp r10, 62 ;sprawdzenie czy koniec alfabetu
	je not_found ;koniec tablicy
	inc rdx ;inkrementacja wskaznika na kolejna litere w alfabecie
	inc r10 ;inkrementacja licznika
	jmp main_loop

found:
	mov edx, 0 ;czyszczenie rejestru pod wynik reszty z dzielenia
	mov eax, r10d ;przeniesienie licznika petli do eax celem podzielenia go
	mov ecx, 9 ;wpisanie dzielnika do ecx
	div ecx ;dzielenie licznika petli przez 9
	mov cl, 10 ;wpisanie do cl 10 celem wymnozenia wyniku poprzedniego dzialania przez 10
	mul cl ;mnozenie al przez cl
	add eax, edx ;dodanie do wyniku reszty z dzielenia przez 9
	add eax, 11 ;korekta ze wzgledu na indeksowanie tablicy od 0 a nie od 1
	jmp end_proc

not_found:
	mov rax, 0
	mov rdx, 0
	mov dl, [rcx]
	sub rax, rdx
	cmp rax, -100
	jl end_proc ;jesli mniejsze 
	sub rax, 300
	jmp end_proc

end_proc:
	pop rdx ;dla bezpieczenstwa przywracamy zapamietane rejestry
	pop rcx
	pop rbx
	ret

asm_encrypt ENDP

;---------------------------------------------------------------------------

asm_decrypt PROC; char* loaded_text, char* shuffled_alphabet_tab, int index 

	push rbx
	push rcx
	push rdx ;dla bezpieczenstwa zapamietujemy rejestry

	add rcx, r8 ;inkrementacja wskaznika o indeks
	mov rax, [rcx] ;zapamietanie indeksu y w alfabecie
	sub rax, '0'
	;dec rax
	inc rcx ;inkrementacja wskaznika w celu uzyskania adresu indeksu x
	mov r11, [rcx] ;zapamietanie indeksu x w alfabecie
	sub r11, '0'
	;dec r11
	xor rdi, rdi ;wyzerowanie rdi
	mov dil, 9 ;
	mul dil ;mnozenie al przez dil
	add eax, r11d ;
	sub eax, 10 ;korekta ze wzgledu na indeksowanie alfabetu od 1 a nie od 0
	mov cl, al
	xor rax, rax
	mov al, cl
	add rdx, rax ;
	mov rax, [rdx] ;

	pop rdx ;dla bezpieczenstwa przywracamy zapamietane rejestry
	pop rcx
	pop rbx
	ret

asm_decrypt ENDP

;---------------------------------------------------------------------------

asm_decrypt_negative PROC; char* loaded_text, int index 
	
	push rbx
	push rcx
	push rdx ;dla bezpieczenstwa zapamietujemy rejestry 

	inc rdx
	add rcx, rdx
	mov r9, [rcx]
	sub r9, '0'
	inc rcx
	mov r10, [rcx]
	sub r10, '0'
	inc rcx
	mov r11, [rcx]
	sub r11, '0'
	cmp r9, 3
	jl continue
	sub r9, 3
continue:
	xor rcx, rcx
	xor rax, rax
	mov rcx, 10
	mov rax, r9
	mul cl
	add rax, r10
	mul cl
	add rax, r11

	pop rdx ;dla bezpieczenstwa przywracamy zapamietane rejestry
	pop rcx
	pop rbx
	ret

asm_decrypt_negative ENDP

END