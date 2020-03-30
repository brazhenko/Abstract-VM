%{
#include "AVMLexer.h"
#include "AVMParser.yy.hpp"
%}

%%


"push"					{return AVM_PUSH;}
"pop"					{return AVM_POP;}
"dump"					{return AVM_DUMP;}
"assert"				{return AVM_ASSERT;}
"add"					{return AVM_ADD;}
"sub"					{return AVM_SUB;}
"mul"					{return AVM_MUL;}
"div"					{return AVM_DIV;}
"mod"					{return AVM_MOD;}
"print"					{return AVM_PRINT;}
"exit"					{return AVM_EXIT;}

"int8"					{return AVM_INT8_TYPE;}
"int16"					{return AVM_INT16_TYPE;}
"int32"					{return AVM_INT32_TYPE;}
"float"					{return AVM_FLOAT_TYPE;}
"double"				{return AVM_DOUBLE_TYPE;}

"("						{return AVM_OPEN_BR;}
")"						{return AVM_CLOSE_BR;}

;;						{return AVM_EOR;}
;.*						{;}
[-]?[0-9]+ 				{return N;}
[-]?[0-9]+[.][0-9]+		{return Z;}
'\n' 					{return SEP;}
[\t\v\r\f ]+			{;}
.						{return AVM_UNKNOWN;}

%%

int yywrap()
{
	return 1;
}