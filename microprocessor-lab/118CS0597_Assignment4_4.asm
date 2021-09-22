
;<Factorial of a number between 0-8>

jmp start

;data

;input: number between 0 and 8 at 2200H
;output: lower byter of answer at address 2201H and higher byte at 2202H 
;8!=40320 so the answer must be 16 bits

;code
start: nop

LXI SP, 27FFH
LDA 2200H
CPI 02H
JC LAST
MVI D, 00H
MOV E, A
DCR A
MOV C, A
CALL FACTO
XCHG
SHLD 2201H
JMP END
LAST: LXI H, 0001H
END: SHLD 2201H
HLT

FACTO: LXI H, 0000H
MOV B, C
BACK: DAD D
DCR B
JNZ BACK
XCHG
DCR C
CNZ FACTO
RET