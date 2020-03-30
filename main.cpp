#include <iostream>
#include <FactoryOperand.h>
#include <Exceptions/AVMException.h>
#include "Service/AVM.h"
#include "StackMachine.h"


# define ADD_INS(ITYPE, OTYPE, VALUE) { \
	StackMachine::Instance().AddInstruction( \
			Instruction( \
			ITYPE, \
			fo.createOperand(OTYPE, VALUE), \
			"DEFAULT INSTRUCTION", \
			-1) \
	);\
}

int yyparse();

int main(int argc, char **argv)
{
	yyparse();


	return 0;

	AVM::Context context;

	try {
		context = parseAVMArgv(argc, argv);
	}
	catch (AVM::OptionRequiresAnArguement &e) {
		std::cerr << e.what() << std::endl;
		// std::cerr << getUsage() << std::endl;
		std::cerr << "USAGE" << std::endl;
		return EXIT_FAILURE;
	}
	catch (AVM::NeedHelp&) {
		// std::cerr << getUsage() << std::endl;
		std::cerr << "USAGE" << std::endl;
		return EXIT_FAILURE;
	}
	catch (AVM::UnknownOption &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cerr << "Unknown exception" << std::endl;
		return EXIT_FAILURE;
	}

	for (const auto& f : context.filesToExecute)
	{
		try {
			ExecuteFile(f);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		catch (...) {

		}
	}

	return 0;


	try {
		StackMachine::Instance().Execute();
	}
	catch (AVM::Exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (std::exception &e) {
		std::cerr << "Standard exception : " << e.what() << std::endl;
		return EXIT_FAILURE + 1;
	}
	catch (...) {
		std::cerr << "Unknown exception" << std::endl;
		return EXIT_FAILURE;
	}




	FactoryOperand fo;
//	ADD_INS(eInstructionType::push, eOperandType::Int8, "20000")
//	ADD_INS(eInstructionType::push, eOperandType::Int8, "20000")
//	ADD_INS(eInstructionType::add, eOperandType::None, "")
//
//	ADD_INS(eInstructionType::push, eOperandType::Int8, "30")
//	ADD_INS(eInstructionType::push, eOperandType::Int8, "20")
//	ADD_INS(eInstructionType::push, eOperandType::Int8, "12")
//	ADD_INS(eInstructionType::push, eOperandType::Int8, "10")
//	ADD_INS(eInstructionType::add, eOperandType::None, "")
//
//	ADD_INS(eInstructionType::add, eOperandType::None, "")
//
//	ADD_INS(eInstructionType::add, eOperandType::None, "")
//	ADD_INS(eInstructionType::add, eOperandType::None, "")
//	ADD_INS(eInstructionType::dump, eOperandType::None, "")
//
//	ADD_INS(eInstructionType::exit, eOperandType::None, "")

	return 0;
}