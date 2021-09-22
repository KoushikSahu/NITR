
;<Store the number of set bits in content of register D in register B>

jmp start

;data


;code
start: nop

;content of D register considered
;Count of set bits stored in B register at end
;answer at B register

MVI B, 00H
MVI C, 08H
MOV A, D
BACK: RAR
JNC SKIP
INR B
SKIP: DCR C
JNZ BACK

hlt