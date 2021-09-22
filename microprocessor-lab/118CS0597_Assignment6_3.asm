
;<square of number between 0-9 using table of squares>

jmp start

;data

;Input: Number between 0-9 at 2000H
;Output: Square of input at 2001H
;Since 9*9=81 we can store the answer in 8 byte memory location

;code
start: nop

;generates lookup table
MVI A, 00H
STA 3000H
MVI A, 01H
STA 3001H
MVI A, 04H
STA 3002H
MVI A, 09H
STA 3003H
MVI A, 010H
STA 3004H
MVI A, 019H
STA 3005H
MVI A, 024H
STA 3006H
MVI A, 031H
STA 3007H
MVI A, 040H
STA 3008H
MVI A, 051H
STA 3009H

;finds square
LXI H, 3000H
LDA 2000H
CPI 0fH
MOV C, A
MVI B, 00H
DAD B
MOV A, M
STA 2001H  

hlt