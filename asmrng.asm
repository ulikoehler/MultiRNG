
segment .data USE32
    amountPrompt: db "Amount:",0
    modPrompt db "mod:",0
    s0Prompt db "s_0:",0
    intAsString: db "%d",10,13,0
    ;Used by IO functions
    int_format	    db  "%i", 0

segment .bss USE32

segment .text USE32

global _main
global _bbshub
global read_int
global print_int

extern _printf
extern _scanf
extern _strtol
_main:
    ;Prompt for modulus
    push modPrompt
    call _printf
    add esp,4
    ;Read modulus
    call read_int
    push eax

    ;Prompt for starting value
    push s0Prompt
    call _printf
    add esp,4
    ;Read starting value
    call read_int
    push eax

    ;Prompt for amount
    push amountPrompt
    call _printf
    add esp,4
    ;Read amount
    call read_int
    push eax

    call _bbshub

    add esp,12
    mov eax,0
    ret

_bbshub:
    pop ecx ;Amount
    pop ebx;Modulus
    ;Main loop
    jmp loop_start

loop_start:
    pop eax ;Last starting value
    mov edx,eax ;copy value of edx to eax for muliplication
    mul edx ;Calculate the square of eax=last i (and edx=eax) and store in eax
    div ebx ;Calculate (eax=s^2)mood(ebx=modulus) and save in edx
    ;Display result
    add esp,8
    push edx ;Is used bym _printf and popped in next iteration
    push intAsString
    call _printf
    add esp,4
    ;Check if loop condition is fulfuilled
    loop loop_start ;Decrement ecx and goto loop_start if ecx != 0

    ;;;;Loop end
    add esp,4
    ret
;;;;;;;;;;;;
read_int:
	enter	4,0
	pusha
	pushf

	lea	eax, [ebp-4]
	push eax
	push dword int_format
	call _scanf
	pop	ecx
	pop	ecx

	popf
	popa
	mov	eax, [ebp-4]
	leave
	ret
