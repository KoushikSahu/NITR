
;<Program title>

jmp start

;data


;code
start: nop

LXI H, 2000H
MOV A, M
INX H
SUB M
INX H
MOV M, A

hlt