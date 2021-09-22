CC=gcc

calc: lex.yy.c calc.tab.c calc.c
	$(CC) lex.yy.c calc.tab.c calc.c -o calc
lex.yy.c: calc.l calc.tab.h
	flex calc.l
calc.tab.c calc.tab.h: calc.y
	bison -d calc.y
clean:
	rm calc.tab.c calc.tab.h lex.yy.c calc
