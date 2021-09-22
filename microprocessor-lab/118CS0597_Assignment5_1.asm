
;<BCD to binary>

jmp start

;data

;input: 2 digit number at 200H
;output: equivalent binary at 300H

;code
start: nop

LDA 200H
MOV B, A 
ANI 0fH
MOV C, A
MOV A, B
ANI 0f0H
RRC
RRC
RRC
RRC
MOV B, A
XRA A
MVI D, 0AH
sum: ADD D
DCR B
JNZ sum
ADD C
STA 300H

hlt