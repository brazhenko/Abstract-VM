#include <iostream>

#include "StackMachine.h"

#define ADD_INSTRUCTION(E_INST_TYPE, LPINSTRUCTION) { \
StackMachine::Instance().AddInstruction({E_INST_TYPE, LPINSTRUCTION});\
}

int main(int argc, char **av)
{
	StackMachine::Instance().AddInstruction({eInstructionType::add, nullptr});
	ADD_INSTRUCTION(eInstructionType::add, nullptr);
	std::cout << "Hello, World!" << std::endl;
	return 0;
}