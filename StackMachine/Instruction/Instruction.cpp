//
// Created by 17641238 on 25.03.2020.
//

#include "Instruction.h"

Instruction::Instruction(eInstructionType type, const IOperand *operand)
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
