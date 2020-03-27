//
// Created by 17641238 on 25.03.2020.
//

#include <iostream>
#include <Exceptions/AVMException.h>
#include "StackMachine.h"

StackMachine& StackMachine::Instance()
{
	static StackMachine instance;
	return instance;
}

StackMachine& StackMachine::operator=(StackMachine& s)
{
	return s;
}

void StackMachine::Execute()
{
	for(op = instructions_.begin(); op != instructions_.end(); op++)
	{
		switch (op->getType())
		{
		case eInstructionType::push:
			std::cerr << "PUSH " << op->getOperand()->toString() << std::endl;
			Push(op->getOperand());
			break;
		case eInstructionType::pop:
			std::cerr << "POP" << std::endl;
			Pop();
			break;
		case eInstructionType::dump:
			std::cerr << "DUMP" << std::endl;
			Dump();
			break;
		case eInstructionType::assert:
			std::cerr << "ASSERT " << op->getOperand()->toString() << std::endl;
			Assert(op->getOperand());
			break;
		case eInstructionType::add:
			std::cerr << "ADD" << std::endl;
			Add();
			break;
		case eInstructionType::sub:
			std::cerr << "SUB" << std::endl;
			Sub();
			break;
		case eInstructionType::mul:
			std::cerr << "MUL" << std::endl;
			Mul();
			break;
		case eInstructionType::div:
			std::cerr << "DIV" << std::endl;
			Div();
			break;
		case eInstructionType::mod:
			std::cerr << "MOD" << std::endl;
			Mod();
			break;
		case eInstructionType::print:
			std::cerr << "PRINT" << std::endl;
			Print();
			break;
		case eInstructionType::exit:
			std::cerr << "EXIT" << std::endl;
			return;
		}
	}
	instructions_.clear();
	// No exit intruction appeared in file
	throw AVM::NoExitInstruction();
}

void StackMachine::AddInstruction(Instruction in)
{
	instructions_.emplace_back(in);
}

void StackMachine::Push(IOperand *op)
{
	stack_.emplace_back(op);
}

void StackMachine::Pop()
{
	if (stack_.empty())
		throw AVM::EmptyStack(op->getLineNum(),
								op->getInstruction()
		);
	stack_.pop_back();
}

void StackMachine::Dump() const
{
	for (const auto &it: stack_)
		std::cerr << it->toString() << std::endl;
}

void StackMachine::Assert(const IOperand *op)
{

}

void StackMachine::Add()
{

}

void StackMachine::Sub()
{

}

void StackMachine::Mul()
{

}

void StackMachine::Div()
{

}

void StackMachine::Mod()
{

}

void StackMachine::Print() const
{

}

