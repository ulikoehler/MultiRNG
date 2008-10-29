;This is a cleanroom recreation of Agner Fog's ReadTSC function. See http://agner.org for futher information!
;Copyright (c) 2008 Uli Koehler
;Compatible with nasm: http://nasm.sourceforge.net

section .txt
global _ReadTSC

_ReadTSC:
    rdtsc                          ;Read timestep counter
    ret
	
