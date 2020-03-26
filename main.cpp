#include <iostream>
#include <FactoryOperand.h>
#include <Exceptions/AVMException.h>

#include "StackMachine.h"


int main(int argc, char **av)
{
	FactoryOperand fo;

	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
								fo.createOperand(eOperandType::Int8, "10")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
			fo.createOperand(eOperandType::Int8, "10")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
			fo.createOperand(eOperandType::Int8, "10")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
			fo.createOperand(eOperandType::Double, "10.12345")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::dump,
			fo.createOperand(eOperandType::None, "")));
	StackMachine::Instance().Execute();

	try
	{
		throw AVM::SyntaxError(1, "ABCDEEFGFEFASLFKnmdsscds", "token23");
	}
	catch (AVM::SyntaxError &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}