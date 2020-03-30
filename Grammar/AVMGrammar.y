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


void yyerror(const char *msg)
{
	throw AVM::SyntaxError(-1, "LINE", "TOKEN");
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
	struct yaccInstruction *inst;
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
	| INSTR SEPSEQ INSTRUCTIONS
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
		ADD_INS(eInstructionType::push, $2->valueType, $2->val);
	}
	| AVM_POP
	{
		ADD_INS(eInstructionType::pop, eOperandType::None, "");
	}
	| AVM_DUMP
	{
		ADD_INS(eInstructionType::dump, eOperandType::None, "");
	}
	| AVM_ASSERT VALUE
	{
		ADD_INS(eInstructionType::assert, $2->valueType, $2->val);
	}
	| AVM_ADD
	{
		ADD_INS(eInstructionType::add, eOperandType::None, "");
	}
	| AVM_SUB
	{
		ADD_INS(eInstructionType::sub, eOperandType::None, "");
	}
	| AVM_MUL
	{
		ADD_INS(eInstructionType::mul, eOperandType::None, "");
	}
	| AVM_DIV
	{
		ADD_INS(eInstructionType::div, eOperandType::None, "");
	}
	| AVM_MOD
	{
		ADD_INS(eInstructionType::mod, eOperandType::None, "");
	}
	| AVM_PRINT
	{
		ADD_INS(eInstructionType::print, eOperandType::None, "");
	}
	| AVM_EXIT
	{
		ADD_INS(eInstructionType::exit, eOperandType::None, "");
	}
	;

VALUE :
	AVM_INT8_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{
		printf("int8: %s\n", $3);
		$$ = new yaccValue();
		$$->valueType = eOperandType::Int8;
		$$->val = $3;
	}
	| AVM_INT16_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{
		printf("int16: %s\n", $3);
		$$ = new yaccValue();
		$$->valueType = eOperandType::Int16;
		$$->val = $3;
	}
	| AVM_INT32_TYPE AVM_OPEN_BR N AVM_CLOSE_BR
	{
		printf("int32: %s\n", $3);
		$$ = new yaccValue();
		$$->valueType = eOperandType::Int32;
		$$->val = $3;
	}
	| AVM_FLOAT_TYPE AVM_OPEN_BR Z AVM_CLOSE_BR
	{
		printf("float: %s\n", $3);
		$$ = new yaccValue();
		$$->valueType = eOperandType::Float;
		$$->val = $3;
	}
	| AVM_DOUBLE_TYPE AVM_OPEN_BR Z AVM_CLOSE_BR
	{
		printf("double: %s\n", $3);
		$$ = new yaccValue();
		$$->valueType = eOperandType::Double;
		$$->val = $3;
	}
	;

%%
