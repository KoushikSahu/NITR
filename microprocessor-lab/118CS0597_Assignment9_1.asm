
;<Searching number in array>

jmp start

;data

;input: array size at 2000H, number to be found at 2001H, n numbers starting from 2002H
;output: number at 200H if found else 00 at 200H

;code
start: nop

LXI H, 2000H
MOV C, M
INX H
MOV B, M
MOV A, B
LOOP: INX H
CMP M
JZ FOUND
DCR C
JNZ LOOP
MVI A, 00H
STA 200H
FOUND: STA 200H

hlt