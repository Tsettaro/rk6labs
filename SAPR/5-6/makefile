T23: lex.yy.c y.tab.c
	cc y.tab.c lex.yy.c -o T23

lex.yy.c: y.tab.c t23.l
	flex t23.l

y.tab.c: t23.y
	yacc -vd t23.y

clean:
	rm -rf lex.yy.c y.tab.c y.tab.h T23
