%{
#include <stdio.h>
#include <stdlib.h>
#include "StackMachine.h"
#include "FactoryOperand.h"
#include <vector>
#include <iostream>
#include "IOperand.h"
#include "Instruction.h"
#include "Exceptions/AVMException.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yychar;
extern char *yydebug;

void yyerror(const char *msg)
{
	std::cerr << msg  << " " << yylineno<< std::endl;
	printf("yychar: %d\n", yychar);
	// throw AVM::SyntaxError(yylineno, "LINE", "TOKEN");
}

struct yaccValue
{
	std::string val;
	eOperandType valueType;
};

%}

%token N Z SEP COMMENT
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

%union {
	char *string;
	struct yaccValue *val;
}

%token  AVM_INT8_TYPE AVM_INT16_TYPE AVM_INT32_TYPE AVM_FLOAT_TYPE AVM_DOUBLE_TYPE
%token AVM_OPEN_BR AVM_CLOSE_BR
%type <string> N Z
%type <val> VALUE
%type <inst> INSTR

%%

S :
	INSTRUCTIONS
	;

INSTRUCTIONS :
	| INSTR
	| SEPSEQ INSTRUCTIONS
	| INSTR SEPSEQ INSTRUCTIONS
	| error '\n'
	;

SEPSEQ:
	SEPARATOR
	| SEPARATOR SEPSEQ
	;

SEPARATOR:
	SEP
	| COMMENT
	;

INSTR :
	AVM_PUSH VALUE
	{
		ADD_INS(eInstructionType::push, $2->valueType, $2->val, yylineno);
		delete $2;
	}
	| AVM_POP
	{
		ADD_INS(eInstructionType::pop, eOperandType::None, "", yylineno);
	}
	| AVM_DUMP
	{
		ADD_INS(eInstructionType::dump, eOperandType::None, "", yylineno);
	}
	| AVM_ASSERT VALUE
	{
		ADD_INS(eInstructionType::assert, $2->valueType, $2->val, yylineno);
		delete $2;
	}
	| AVM_ADD
	{
		ADD_INS(eInstructionType::add, eOperandType::None, "", yylineno);
	}
	| AVM_SUB
	{
		ADD_INS(eInstructionType::sub, eOperandType::None, "", yylineno);
	}
	| AVM_MUL
	{
		ADD_INS(eInstructionType::mul, eOperandType::None, "", yylineno);
	}
	| AVM_DIV
	{
		ADD_INS(eInstructionType::div, eOperandType::None, "", yylineno);
	}
	| AVM_MOD
	{
		ADD_INS(eInstructionType::mod, eOperandType::None, "", yylineno);
	}
	| AVM_PRINT
	{
		ADD_INS(eInstructionType::print, eOperandType::None, "", yylineno);
	}
	| AVM_EXIT
	{
		ADD_INS(eInstructionType::exit, eOperandType::None, "", yylineno);
	}
	;

VALUE :
	AVM_INT8_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{
		$$ = new yaccValue();
		$$->valueType = eOperandType::Int8;
		$$->val = $3;
		free($3);
	}
	| AVM_INT16_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{
		$$ = new yaccValue();
		$$->valueType = eOperandType::Int16;
		$$->val = $3;
		free($3);
	}
	| AVM_INT32_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{
		$$ = new yaccValue();
		$$->valueType = eOperandType::Int32;
		$$->val = $3;
		free($3);
	}
	| AVM_FLOAT_TYPE AVM_OPEN_BR Z AVM_CLOSE_BR
	{
		$$ = new yaccValue();
		$$->valueType = eOperandType::Float;
		$$->val = $3;
		free($3);
	}
	| AVM_DOUBLE_TYPE AVM_OPEN_BR Z AVM_CLOSE_BR
	{
		$$ = new yaccValue();
		$$->valueType = eOperandType::Double;
		$$->val = $3;
		free($3);
	}
	;

%%
