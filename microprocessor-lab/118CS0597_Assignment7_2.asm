
;<Adding array of five 16 bit numbers>

jmp start

;data

;Input: five 16 bit numbers starting from 2000H - 2009H
;Ouput: lower byte at 2010H, higher byte at 2011H

;code
start: nop

LHLD 2000H
XCHG
LHLD 2002H
DAD D
XCHG
LHLD 2004H
DAD D
XCHG
LHLD 2006H
DAD D
XCHG
LHLD 2008H
DAD D
SHLD 2010H

hlt