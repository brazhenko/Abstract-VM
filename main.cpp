#include <iostream>
#include <FactoryOperand.h>

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
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::pop,
			fo.createOperand(eOperandType::None, "")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::print,
			fo.createOperand(eOperandType::None, "")));
	StackMachine::Instance().Execute();




	std::cout << "Hello, World!" << std::endl;
	return 0;
}