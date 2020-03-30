%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();


void yyerror(const char *msg)
{
    fprintf(stderr, "%s !!\n", msg);
}

%}


%token N Z SEP

%token AVM_POP
%token AVM_PUSH
%token AVM_DUMP
%token	AVM_ASSERT
%token	AVM_ADD
%token	AVM_SUB
%token	AVM_MUL
%token	AVM_DIV
%token	AVM_MOD
%token	AVM_PRINT
%token	AVM_EXIT

%token AVM_INT8_TYPE AVM_INT16_TYPE AVM_INT32_TYPE AVM_FLOAT_TYPE AVM_DOUBLE_TYPE

%token AVM_OPEN_BR AVM_CLOSE_BR


%%

S :
	INSTR 		{printf("ok00\n\n");}
	| INSTR S 	{printf("ok01\n\n");}
	| INSTR SEP	{printf("ok02\n\n");}
	;

INSTR :
	AVM_PUSH VALUE 		{printf("value %d\n", $2);}
	| AVM_POP		{printf("value %d\n", $1);}
	| AVM_DUMP
	| AVM_ASSERT VALUE
	| AVM_ADD
	| AVM_SUB
	| AVM_MUL
	| AVM_DIV
	| AVM_MOD
	| AVM_PRINT
	| AVM_EXIT
	;

VALUE :
	AVM_INT8_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{printf("%d - %d\n", $1, $3);}
	| AVM_INT16_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{printf("%d - %d\n", $1, $3);}
	| AVM_INT32_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{printf("%d - %d\n", $1, $3);}
	| AVM_FLOAT_TYPE AVM_OPEN_BR Z AVM_CLOSE_BR
	{printf("%d - %d\n", $1, $3);}
	| AVM_DOUBLE_TYPE AVM_OPEN_BR Z AVM_CLOSE_BR
	{printf("%d - %d\n", $1, $3);}
	;

%%
