
;<Hex to ASCII using subroutine>

jmp start

;data

;Input: Hexadecimal number at 2000H
;Output: Equivalent ASCII at 2001H(lower byte) and 2002H(higher byte)

;code
start: nop

LDA 2000H
MOV B, A
ANI 0fH
CALL ASCII
STA 2001H
MOV A, B
ANI 0f0H
RLC
RLC
RLC
RLC
CALL ASCII
STA 2002H
HLT

ASCII: CPI 0aH
JC SKIP
ADI 07H
SKIP: ADI 30H
RET