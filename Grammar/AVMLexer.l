%{
#include "AVMLexer.h"
%}

%%

;;						return EOR;
;.+						return COMMENT;
[-]?[0..9]+ 			return INTEGER;
[-]?[0..9]+.[0..9]+		return FLOATING;
'\n'+ 					return SEPARATOR;
.						return UNKNOWN;

%%

int yywrap()
{
	return 1;
}