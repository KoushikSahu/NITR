
;<Add array of 10 numbers>

jmp start

;data

;Input: Ten 8-bit numbers starting at 2000H - 2009H
;Output: sum at 2010H and carry at 2011H

;code
start: nop

MVI B, 0aH
LXI H, 2000H
MVI A, 00
MVI C, 00
STMT1: ADD M
INR L
JNC STMT2
INR C
STMT2: DCR B
JNZ STMT1	
STA 2010H
MOV A, C
STA 2011H

hlt