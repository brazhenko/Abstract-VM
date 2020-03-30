

all: Scanner Parser

Scanner: AVMLexer.l
	lex -o AVMLexer.ll.cpp AVMLexer.l
	sed -i "" -- 's/register//g' AVMLexer.ll.cpp

Parser: AVMGrammar.y
	yacc -d -o AVMParser.yy.cpp AVMGrammar.y