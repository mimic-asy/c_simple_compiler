#最終ターゲット
mycalc : test.tab.o lex.yy.o header.o
	g++ -o mycalc test.tab.o lex.yy.o header.o

#構文解析
yy.tab.o : test.y
	bison -d test.y
	g++ -c test.tab.c

#字句解析
lex.yy.o : test.l
	flex test.l
	g++ -c lex.yy.c

header.o : header.cpp
	g++ -c header.cpp


# clean:; rm mycalc y.tab.c y.tab.h lex.yy.cc *.o
clean:; rm mycalc test.tab.c test.tab.h lex.yy.c *.o