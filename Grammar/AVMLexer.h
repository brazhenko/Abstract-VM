//
// Created by 17641238 on 27.03.2020.
//

#ifndef AVM_AVMLEXER_H
#define AVM_AVMLEXER_H

# define AVM_EOF_INTERACTIVE ";;"

enum class AVMTokens
{
	EOR,
	COMMENT,
	INTEGER,
	FLOATING,
	SEPARATOR,
	UNKNOWN
};

#endif //AVM_AVMLEXER_H
