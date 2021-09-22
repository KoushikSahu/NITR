
;<Adding two 16 bit numbers>

jmp start

;data

;input: input must be present in DE and HL register pair
;output: starting at 40H

;code
start: nop

LXI SP, 1000H
;uncomment the following 3 lines(line 17-19)
;to take input from 2000H and 20002H
;LHLD 2000H
;XCHG
;LHLD 2002H
PUSH H
POP B
LXI H, 0000H
SHLD 0042H
STMT1: DAD D
JNC STMT2
PUSH H
LHLD 0042H
INX H
SHLD 0042H
POP H
STMT2: DCX B
MOV A, B
ORA C
JNZ STMT1
SHLD 0040H

hlt