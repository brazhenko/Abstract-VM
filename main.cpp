#include <iostream>
#include <FactoryOperand.h>
#include <Exceptions/AVMException.h>

#include "StackMachine.h"


int main(int argc, char **av)
{
	FactoryOperand fo;




	StackMachine::Instance().AddInstruction(
			Instruction(
					eInstructionType::push,
					fo.createOperand(eOperandType::Int8, "10"),
					"push 10",
					1)
			);

	StackMachine::Instance().AddInstruction(
			Instruction(
					eInstructionType::pop,
					fo.createOperand(eOperandType::Int8, ""),
					"pop ",
					2)
	);

	StackMachine::Instance().AddInstruction(
			Instruction(
					eInstructionType::pop,
					fo.createOperand(eOperandType::Int8, ""),
					"pop ",
					3)
	);

	StackMachine::Instance().AddInstruction(
			Instruction(
					eInstructionType::push,
					fo.createOperand(eOperandType::Int8, "10"),
					"push 123",
					1)
	);

	StackMachine::Instance().AddInstruction(
			Instruction(
					eInstructionType::push,
					fo.createOperand(eOperandType::Int8, "10"),
					"push 123",
					1)
	);

	StackMachine::Instance().AddInstruction(
			Instruction(
					eInstructionType::push,
					fo.createOperand(eOperandType::Int8, "10"),
					"push 123",
					1)
	);

	StackMachine::Instance().AddInstruction(
			Instruction(
					eInstructionType::push,
					fo.createOperand(eOperandType::Int8, "10"),
					"push 123",
					1)
	);

//	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
//			fo.createOperand(eOperandType::Int8, "42"), <#initializer#>, 0));
//	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
//			fo.createOperand(eOperandType::Int8, "21"), <#initializer#>, 0));
//	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::push,
//			fo.createOperand(eOperandType::Double, "10.12345"), <#initializer#>,
//			0));
//	StackMachine::Instance().AddInstruction(Instruction(eInstructionType::dump,
//			fo.createOperand(eOperandType::None, ""), <#initializer#>, 0));
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