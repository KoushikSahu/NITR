
;<Hex to binary>

jmp start

;data

;input: hex value at 2000H
;output: binary value at 2005H

;code
start: nop

LXI H, 2000H
MVI D, 00H
XRA A
MOV C, M
LOOP2: ADI 01H
DAA	
JNC LOOP1
INR D
LOOP1: DCR C
JNZ LOOP2
STA 802BH
MOV A, D	
STA 2005H
LXI SP, 80FFH
LXI H, 802BH
LXI B, 2005H
MOV A, M 	
CALL BCDBIN	
STAX B 	
HLT 

BCDBIN: PUSH B 	
MOV B, A 	
ANI 0FH 	
MOV C, A 	
MOV A, B 	
ANI 0F0H 	
RRC 	
RRC 	
RRC 
RRC 
MOV D, A 	 	 		
XRA A 	
MVI E, 0AH 	
SUM: ADD E 	
DCR D 	
JNZ SUM 	
ADD C 	
POP B 	
RET