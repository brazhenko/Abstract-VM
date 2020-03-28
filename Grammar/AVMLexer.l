%{
#include "AVMLexer.h"
%}

%%

;;						return AVMTokens::EOR;
;.+						return AVMTokens::COMMENT;
[-]?[0..9]+ 			return AVMTokens::INTEGER;
[-]?[0..9]+.[0..9]+		return AVMTokens::FLOATING;
'\n'+ 					return AVMTokens::SEPARATOR;
.						return AVMTokens::UNKNOWN;

%%

int yywrap()
{
	return 1;
}