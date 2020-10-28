.CODE

asm_encrypt PROC ;char* loaded_text, char* shuffled_alphabet_tab, int index 

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
	xor rax, rax ;wyzerowanie rax 
	xor rdx, rdx ;wyzerowanie rdx
	mov dl, [rcx] ;przeniesienie znaku, ktory jest szyfrowany do dl
	sub rax, rdx ;odjêcie znaku celem uzyskania ujemnego "kodu ASCII" tego znaku
	cmp rax, -100 ;przyrownanie znaku do -100
	jl end_proc ;jesli znak jest mniejszy ni¿ -100 to koniec
	sub rax, 300 ;jesli nie to odejmij 300
	jmp end_proc

end_proc:

	ret

asm_encrypt ENDP

;---------------------------------------------------------------------------

asm_encrypt_mmx PROC ;char* loaded_text, char* shuffled_alphabet_tab, int index

	mov al, [rcx+r8] ;przeniesienie szukanego znaku do al
	and eax, 0ffh ;wyzerowanie wyzszych bitow w eax
	movd mm0, eax ;wpisanie eax do mm0
	punpckldq mm0, mm0 ;poczatek broadcasta (zapelnienia mm0 szukanym znakiem)
	packssdw mm0, mm0
	packuswb mm0, mm0 ;koniec broadcasta
	xor rax, rax ;wyzerownaie rax
	xor rcx, rcx ;wyzerowanie rcx
	mov ch, 0 ;ustawienie licznika na 7

main_loop:
	movq mm1, qword ptr[rdx] ;wpisanie do wektora kolejnych 8 znaków alfabetu
	pcmpeqb mm1, mm0 ;sprawdzenie, czy w mm1 wystapil szukany znak
	movq rax, mm1 ;przeniesienie wynikowej maski do rax
	cmp rax, 0 ;sprawdzenie czy wynik jest 0
	jne found ;jesli nie to znaczy ze znaleziono znak
	add rdx, 8 ;inkrementacja wskaznika o 8
	inc cl ;inkrementacja licznika
	cmp cl, 8 ;sprawdzenie czy koniec alfabetu
	jne main_loop ;jesli nie koniec to powrot to main_loopa/jesli koniec to not_found

not_found:
	xor rax, rax ;wyzerownaie rax
	movq rdx, mm0 ;zwrocenie szukanego znaku do rdx
	and rdx, 0ffh ;wyzerowanie wyzszeych bitow w celu uzyskania pojedynczego szukanego znaku
	sub rax, rdx ;odjêcie znaku celem uzyskania ujemnego "kodu ASCII" tego znaku
	cmp rax, -100 ;przyrownanie znaku do -100
	jl end_proc ;jesli znak jest mniejszy ni¿ -100 to koniec
	sub rax, 300 ;jesli nie to odejmij 300
	jmp end_proc

found:
	cmp al, 0 ;sprawdzenie czy szukany znak jest w al
	jne finish ;jesli tak to finish
	inc ch ;dekrementacja wskaznika
	shr rax, 8; przesuniecie bitowe o 8 w celu spradzenia czy koljeny znak jest tym szukanym
	jmp found

finish:
	xor rax, rax ;wyzerownaie rax
	mov al, cl ;przeniesienie do al jednego z licznikow
	mov cl, 8 ;wpisanie do cl 8
	mul cl ;pomnozenie go przez 8 (w ktorej ósemce alfaberu by³ znaleziony znak)
	add al, ch; dodanie drugiego licznika (ktory indeks w ostetecznej ósemce mia³ znaleziony znak)

	xor ecx, ecx
	xor edx, edx
	mov ecx, 9 ;wpisanie dzielnika do ecx
	div ecx ;dzielenie licznika petli przez 9
	mov cl, 10 ;wpisanie do cl 10 celem wymnozenia wyniku poprzedniego dzialania przez 10
	mul cl ;mnozenie al przez cl
	add eax, edx ;dodanie do wyniku reszty z dzielenia przez 9

	add eax, 11 ;korekta ze wzgledu na indeksowanie tablicy od 0 a nie od 1

end_proc:
	emms
	ret

asm_encrypt_mmx ENDP

;---------------------------------------------------------------------------

asm_decrypt PROC; char* loaded_text, char* shuffled_alphabet_tab, int index 

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
	ret

asm_decrypt ENDP

;---------------------------------------------------------------------------

asm_decrypt_negative PROC; char* loaded_text, int index 

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
	ret

asm_decrypt_negative ENDP

END