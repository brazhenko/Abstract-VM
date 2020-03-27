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
	Instruction(eInstructionType type, const IOperand *operand, std::string instruction,
			int lineNum);
	[[nodiscard]] eInstructionType getType() const;
	[[nodiscard]] IOperand* getOperand() const;
	[[nodiscard]] int getLineNum() const;
	[[nodiscard]] std::string getInstruction() const;
private:
	eInstructionType type_;
	IOperand *operand_;
	const std::string instruction_;
	const int lineNum_;
};

#endif //AVM_INSTRUCTION_H
