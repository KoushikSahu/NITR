
;<Factorial of a number from 0 to 8 with inputs in direct addressing mode>

jmp start

;data

;input: number from 0 to 8 at 0597H
;output: lower byte at 1024H and higher byte at 1025H
;to convert answer to decimal do 256*[1025H] + [1024H]

;code
start: nop

LDA 0597H          ;input taken to accumulator(direct addressing)
CPI 02H            ;compare accumulator to immediate value #2(immediate addressing)
JC LAST            ;if carry is set(meaning 2 is greater than accumulator value) we jump to label LAST
MVI D, 00H         ;initialize D to immediate value #0(immediate addressing)
MOV E, A           ;move the content of accumulator to register E(register addressing)
DCR A              ;decrement the value of accumulator by 1(register addressing)
MOV C, A           ;move the content of accumulator to register C(register addressing)
CALL FACTORIAL     ;call the subroutine FACTORIAL(unconditional call)
XCHG               ;exchange the content of HL reg pair with DE reg pair
SHLD 1024H         ;store the content of HL reg pair to 1024H and 1025H(direct addressing)
JMP END            ;unconditional jump to label END(unconditional jump)
LAST: LXI H, 0001H ;LAST label, load the content of HL reg pair with immediate value #1(immediate addressing)
END: SHLD 1024H    ;store the content of HL reg pair to 1024 and 1025H(direct addressing)
HLT

FACTORIAL: LXI H, 0000H ;initialize HL reg pair with immediate value #0(immediate addressing)
MOV B, C                ;move content of C to register B(register addressing)
BACK: DAD D             ;add the content of DE reg pair to HL reg pair(register addressing)
DCR B                   ;decrement the content of B(register addressing)
JNZ BACK                ;if [B]!=0 then we jump to label BACK(conditional jump)
XCHG                    ;exchange the content of DE reg pair with HL reg pair
DCR C                   ;decrement the content of C register(register addressing)
CNZ FACTORIAL           ;if [C]!=0 then call factorial subroutine(conditional call)
RET                     ;return to the line after the call of subroutine