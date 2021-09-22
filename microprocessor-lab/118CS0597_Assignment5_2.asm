
;<Adding 2 four digit BCD number>

jmp start

;data

;input: BCD at HL register pair and other at DE register pair
;output: sum at 300H(lower byte) and 301H(higher byte)

;code
start: nop

;use the below two statements to give input into HL and DE register pair
LXI H, 0e2dH
LXI D, 1282H
MOV A, L
ADD E
DAA
STA 300H
MOV A, H
ADC D
DAA
STA 301H

hlt