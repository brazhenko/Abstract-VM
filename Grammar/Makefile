all:
	lex -o AVMLexer.ll.cpp AVMLexer.l
	sed -i "" -- 's/register//g' AVMLexer.ll.cpp
	yacc -o AVMParser.yy.cpp AVMGrammar.y