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
			fo.createOperand(eOperandType::Int8, "42")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
			fo.createOperand(eOperandType::Int8, "21")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
			fo.createOperand(eOperandType::Double, "10.12345")));
	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::dump,
			fo.createOperand(eOperandType::None, "")));
	// StackMachine::Instance().AddInstruction(Instruction(eInstructionType::exit,
	//		fo.createOperand(eOperandType::None, "")));

	try
	{
		StackMachine::Instance().Execute();
	}
	catch (AVM::Exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (std::exception &e)
	{
		std::cerr << "Standard exception : " << e.what() << std::endl;
		return EXIT_FAILURE + 1;
	}
	catch (...)
	{
		std::cerr << "Unknown exception" << std::endl;
		return EXIT_FAILURE + 2;
	}

	return 0;
}