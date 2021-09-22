
;<Largest number in series of 10 numbers using direct addressing mode for inputs>

jmp start

;data

;input: 10 numbers starting from 0597H
;output: largest number at 1024H
;in order to use direct addressing the array size is assumed to be 10

;code
start: nop

LDA 0597H         ;load the content of 597H to accumulator(direct addressing)
MOV B, A          ;move content of accumulator to B(register addressing)
LDA 0598H         ;load the content of 598H to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP1          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP1)
MOV B, A          ;move content of accumulator to register B(register addressing)
SKIP1: LDA 0599H  ;load the content of 598H to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP2          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP2)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP2: LDA 059AH  ;load the content of 59AH to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP3          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP3)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP3: LDA 059BH  ;load the content of 59BH to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP4          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP4)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP4: LDA 059CH  ;load the content of 59CH to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP5          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP5)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP5: LDA 059DH  ;load the content of 59DH to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP6          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP6)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP6: LDA 059EH  ;load the content of 59EH to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP7          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP7)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP7: LDA 059FH  ;load the content of 59FH to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP8          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP8)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP8: LDA 05A0H  ;load the content of 5A0H to accumulator(direct addressing)
CMP B             ;compare accumulator with content of B(register addressing)
JC SKIP9          ;if carry is set(content of B is greater than content of accumulator jump to label SKIP9)
MOV B, A          ;move content of accumulator to B(register addressing)
SKIP9: LXI H, 1024H  ;store 1024H in HL reg pair(immediate addressing)
MOV M, B          ;move the content of B register to address pointed to by HL reg pair(indirect addressing)

hlt