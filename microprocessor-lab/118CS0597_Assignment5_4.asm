
;<square root of a 8 bit number>

jmp start

;data

;input: 8 bit number at 2000H
;output: 8 bit number at 2001H

;***warning: works only when the given input is a perfect square*** 

;code
start: nop

MVI D, 01
MVI E, 01
LDA 2000H
stmt2: SUB D
JZ stmt1
INR D
INR D
INR E
JMP stmt2
stmt1: MOV A, E
STA 2001H

hlt