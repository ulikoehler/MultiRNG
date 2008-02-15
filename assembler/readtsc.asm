;This is a cleanroom recreation of Agner Fog's ReadTSC function. See http://agner.org for futher information!
;Copyright (c) 2008 Uli Koehler
;Compatible with nasm: http://nasm.sourceforge.net

section .txt
global _ReadTSC

_ReadTSC:
    ;sub     eax, eax               ;Set eax to 0
    rdtsc                          ;Read timestep counter
    ;push    eax
    ;push    edx
    ;sub     eax, eax
    ;pop     edx
    ;pop     eax
    ret
	
