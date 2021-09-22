
;<Adding 16 bit odd numbers from an array of 10 numbers>

jmp start

;data

;Input: 16 bit numbers from 2000H - 2019H
;Ouput: Sum of the odd numbers in the array with lower bit at 2021H, higher bit at 2020H

;code
start: nop

LXI D, 0000H
LXI H, 1000H 
MVI M, 00H
LXI H, 1001H 
MVI M, 20H
MVI B, 0aH
STMT1: LHLD 1000H
XCHG
LDAX D
ANI 01H
XCHG
JZ STMT2
MOV A, E
ADD M
MOV E, A
INR D
MOV A, D
ADC M
MOV D, A
STMT2: LDA 1000H
ADI 02H
STA 1000H
DCR B
JNZ STMT1
XCHG
SHLD 2020H

hlt