
;<10 numbers hex to BCD>

jmp start

;data


;code
start: nop

LXI 
MVI B, 00H	
XRA A	
MOV C, M
LOOP: ADI 01H	
DAA
JNC SKIP	
INR B
SKIP: DCR C
JNZ LOOP	
MOV L, A	
MOV H, B
SHLD		
HLT