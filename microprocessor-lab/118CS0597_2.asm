
;<Converting 10 hexadecimal numbers to equivalent BCD with inputs in direct addressing mode>

jmp start

;data

;input: 10 hexadecimal numbers starting from 0597H
;output: 10 BCD numbers starting from 1024H

;code
start: nop

LDA 0597H           ;load accumulator with content of 597H(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 1024H          ;store the resultant value present in HL reg pair to 1024H(direct addressing)
LDA 0598H           ;load accumulator with content of 598H(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 1026H          ;store the resultant value present in HL reg pair to 1026H(direct addressing)
LDA 0599H           ;load accumulator with content of 599H(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 1028H          ;store the resultant value present in HL reg pair to 1028H(direct addressing)
LDA 059AH           ;load accumulator with content of 59AH(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 102AH          ;store the resultant value present in HL reg pair to 102AH(direct addressing)
LDA 059BH           ;load accumulator with content of 59BH(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 102CH          ;store the resultant value present in HL reg pair to 102CH(direct addressing)
LDA 059CH           ;load accumulator with content of 59CH(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 102EH          ;store the resultant value present in HL reg pair to 102EH(direct addressing)
LDA 059DH           ;load accumulator with content of 59DH(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 1030H          ;store the resultant value present in HL reg pair to 1030H(direct addressing)
LDA 059EH           ;load accumulator with content of 59EH(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 1032H          ;store the resultant value present in HL reg pair to 1032H(direct addressing)
LDA 059FH           ;load accumulator with content of 59FH(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 1034H          ;store the resultant value present in HL reg pair to 1034H(direct addressing)
LDA 05A0H           ;load accumulator with content of 5A0H(direct addressing)
CALL HEXTOBCD       ;call the subroutine HEXTOBCD(unconditional call)
SHLD 1036H          ;store the resultant value present in HL reg pair to 1036H(direct addressing)
HLT

HEXTOBCD: MOV C, A  ;move the content of accumulator to C register(register addressing) 
MVI D, 00H          ;write immediate value #0 to D register(immediate addressing)
MVI A, 00H          ;write immediate value #0 to A register(immediate addressing)
LOOP: ADI 01H       ;increment the value of accumulator(immediate addressing)
DAA                 ;decimal adjust the accumulator
JNC SKIP            ;jump to label SKIP if carry is reset(conditional jump)
INR D               ;if carry is set the this stmt is called which increments D register(register addressing)
SKIP: DCR C         ;SKIP label, decrement the content of C by 1(register addressing) 
JNZ LOOP            ;if [C]!=0 then jump to LOOP label(conditional jump)
MOV L, A            ;move the content of accumulator to L register(register addressing)
MOV H, D            ;move the content of D register to H register(register addressing)
RET