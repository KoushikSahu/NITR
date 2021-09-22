
;<Multiplication of 8 bit numbers with repititive addition>

jmp start

;data


;code
start: nop

;program supports only 8 bit answer
;multiplicand at 2200H
;multiplier at 2201H
;answer present at 2203H

LDA 2200H
MOV B, A
LDA 2201H
MOV D, A
MVI A, 00H
L1: ADD B
DCR D
JNZ L1
STA 2203H

hlt