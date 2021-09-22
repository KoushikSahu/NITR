
;<Program title>

jmp start

;data


;code
start: nop

LDA 2200H
CMA
ADI 01H
STA 2201H

hlt