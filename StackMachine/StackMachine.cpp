//
// Created by 17641238 on 25.03.2020.
//

#include <iostream>
#include <Exceptions/AVMException.h>
#include <sstream>
#include <FactoryOperand.h>
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
			Push(op->getOperand());
			break;
		case eInstructionType::pop:
			Pop();
			break;
		case eInstructionType::dump:
			Dump();
			break;
		case eInstructionType::assert:
			Assert(op->getOperand());
			break;
		case eInstructionType::add:
			Add();
			break;
		case eInstructionType::sub:
			Sub();
			break;
		case eInstructionType::mul:
			Mul();
			break;
		case eInstructionType::div:
			Div();
			break;
		case eInstructionType::mod:
			Mod();
			break;
		case eInstructionType::print:
			Print();
			break;
		case eInstructionType::exit:
			return;
		}
	}
	instructions_.clear();
	throw AVM::NoExitInstruction();
}

void StackMachine::AddInstruction(Instruction in)
{
	instructions_.emplace_back(in);
}

void StackMachine::Push(const IOperand *operand)
{
	stack_.emplace_back(operand);
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
		std::cout << it->toString() << std::endl;
}

void StackMachine::Assert(const IOperand *operand)
{
	if (stack_.empty())
		throw AVM::EmptyStack(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
				);

	if (stack_.back()->toString() != operand->toString())
		throw AVM::AssertFailed(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
				);
}

void StackMachine::Add()
{
	if (stack_.size() < 2)
		throw AVM::LessThanTwoValuesForBinExp(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
				);

	auto a = stack_.back();
	stack_.pop_back();
	auto b = stack_.back();
	stack_.pop_back();
	auto res = *a + *b;
	stack_.emplace_back(res);
}

void StackMachine::Sub()
{
	if (stack_.size() < 2)
		throw AVM::LessThanTwoValuesForBinExp(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
		);

	auto a = stack_.back();
	stack_.pop_back();
	auto b = stack_.back();
	stack_.pop_back();
	auto res = *b - *a;
	stack_.emplace_back(res);
}

void StackMachine::Mul()
{
	if (stack_.size() < 2)
		throw AVM::LessThanTwoValuesForBinExp(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
		);

	auto a = stack_.back();
	stack_.pop_back();
	auto b = stack_.back();
	stack_.pop_back();
	auto res = *a * *b;
	stack_.emplace_back(res);
}

void StackMachine::Div()
{
	if (stack_.size() < 2)
		throw AVM::LessThanTwoValuesForBinExp(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
		);

	auto a = stack_.back();
	stack_.pop_back();
	auto b = stack_.back();
	stack_.pop_back();
	auto res = *b / *a;
	stack_.emplace_back(res);
}

void StackMachine::Mod()
{
	if (stack_.size() < 2)
		throw AVM::LessThanTwoValuesForBinExp(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
		);

	auto a = stack_.back();
	stack_.pop_back();
	auto b = stack_.back();
	stack_.pop_back();
	auto res = *b % *a;
	stack_.emplace_back(res);
}

void StackMachine::Print() const
{
	if (stack_.empty())
		throw AVM::EmptyStack(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
		);

	if (stack_.back()->getType() != eOperandType::Int8)
		throw AVM::AssertFailed(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction()
		);

	int asciCode;
	std::stringstream ss(stack_.back()->toString());
	ss >> asciCode;
	char toPrint = static_cast<char>(asciCode);

	std::cout << toPrint;
}

std::vector<Instruction>::iterator StackMachine::getCurrentOperation()
{
	return op;
}
