
;<Division of 16 bit number with 8 bit number>

jmp start

;data


;code
start: nop

;dividend goes in 8000H and 8001H
;8000H holding lower order byte and 8001H holding higher order byte
;divisor goes in 8002H

;answer stored in 8050H, 8051H, 8052H 
;quotient at 8050H(lower order byte), 8051(Higher order byte)
;remainder at 8052H

LXI H, 8000H
MOV A, M
INX H
MOV B, M
INX H
MOV C, M
INR B
LXI H, 0000H
LOOP: SUB C
JC SKIP
INCR: INX H
JMP LOOP
SKIP: DCR B
JZ STORE
JMP INCR
STORE: ADD C
XCHG
LXI H, 8050H
MOV M, E
INX H
MOV M, D
INX H
MOV M, A

hlt