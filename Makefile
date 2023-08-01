#最終ターゲット
mycalc : test.tab.o lex.yy.o function.o
	g++ -o mycalc test.tab.o lex.yy.o function.o

#構文解析
test.tab.o : test.y
	bison -d test.y
	g++ -c test.tab.c

#字句解析
lex.yy.o : test.l
	flex test.l
	g++ -c lex.yy.c

function.o : function.cpp
	g++ -o function.o -c function.cpp



# clean:; rm mycalc y.tab.c y.tab.h lex.yy.cc *.o
clean:; rm mycalc test.tab.c test.tab.h lex.yy.c *.o