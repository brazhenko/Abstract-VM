%{
#include "AVMLexer.h"
%}

%%

;;						AVM_EOR;
;.+						AVM_COMMENT;
[-]?[0..9]+ 			AVM_INTEGER;
[-]?[0..9]+.[0..9]+		AVM_FLOATING;
'\n'+ 					AVM_SEPARATOR;
.						AVM_UNKNOWN;

%%

int yywrap()
{
	return 1;
}