
;<Implementing p*q+r*s>

jmp start

;data

;Input: p, q, r, s at address 2200H, 2201H, 2202H, 2203H
;Output: 16 bit answer with lower byte at 2204H, higher byte at 2205H

;code
start: nop

LXI SP, 2300H
LXI H, 2200H
CALL MULTI
PUSH D
INX H
CALL MULTI
POP B
PUSH H
XCHG
DAD B
XCHG
POP H
INX H
MOV M, E
INX H
MOV M, D
HLT

MULTI: MOV C, M
INX H
MOV B, M
PUSH H
MVI H, 00H
MVI A, 00H
UP: ADD B
JNC LOOP
INR H
LOOP: DCR C
JNZ UP
MOV L, A
XCHG
POP H
RET