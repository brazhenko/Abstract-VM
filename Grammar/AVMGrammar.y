%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();


void yyerror(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
}


%}
%%

S :
	INSTR S
	| INSTR
	| INSTR SEP
	;

INSTR :
	"push" VALUE
	| "pop"
	| "dump"
	| "assert" VALUE
	| "add"
	| "sub"
	| "mul"
	| "div"
	| "mod"
	| "print"
	| "exit"
	;
VALUE :
	"int8(" N ")"
	| "int16(" N ")"
	| "int32(" N ")"
	| "float(" Z ")"
	| "double(" Z ")"
	;

N : "[-]?[0..9]+"
	;

Z : "[-]?[0..9]+.[0..9]+"
	;

SEP : "'\n'+"
	;
%%
