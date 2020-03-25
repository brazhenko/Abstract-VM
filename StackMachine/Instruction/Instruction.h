//
// Created by 17641238 on 25.03.2020.
//

#ifndef AVM_INSTRUCTION_H
#define AVM_INSTRUCTION_H

#include "IOperand.h"

enum class eInstructionType
{
	push,
	pop,
	dump,
	assert,
	add,
	sub,
	mul,
	div,
	mod,
	print,
	exit
};

class Instruction
{
public:
	Instruction(eInstructionType, const IOperand*);
	eInstructionType getType() const;
	IOperand* getOperand() const;
private:
	eInstructionType type_;
	IOperand *operand_;
};

#endif //AVM_INSTRUCTION_H
