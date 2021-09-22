
;<Sorting in descending order>

jmp start

;data

;Input: 10 numbers start from address 2200H
;Output: sorting is done inplace so answer starts from 2200H

;code
start: nop

MVI B, 09      
START: LXI H, 2200H 
MVI C, 09H     
BACK: MOV A, M 
INX H          
CMP M          
JNC SKIP        
JZ SKIP        
MOV D, M
MOV M, A
DCX H
MOV M, D
INX H          
SKIP: DCR C     
JNZ BACK       
DCR B          
JNZ START

hlt