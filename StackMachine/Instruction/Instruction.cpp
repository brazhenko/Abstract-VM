//
// Created by 17641238 on 25.03.2020.
//

#include "Instruction.h"

Instruction::Instruction(eInstructionType type, const IOperand *operand,
		const std::string instruction,
		int lineNum)
		: instruction_(instruction), lineNum_{lineNum}
{
	type_ = type;
	operand_ = const_cast<IOperand*>(operand);
}

eInstructionType Instruction::getType() const
{
	return type_;
}

IOperand *Instruction::getOperand() const
{
	return operand_;
}

int Instruction::getLineNum() const
{
	return lineNum_;
}

std::string Instruction::getInstruction() const
{
	return instruction_;
}
