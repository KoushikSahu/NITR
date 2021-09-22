
;<Square root of a number>

jmp start

;data

;input: number at 2000H
;output: square root at 2005H

;code
start: nop

MVI D, 01H
MVI E, 01H
LDA 2000H
STMT1: SUB D
JM STMT2
INR D
INR D
INR E
JMP STMT1
STMT2: MOV A, E
DCR A
STA 2005H

hlt