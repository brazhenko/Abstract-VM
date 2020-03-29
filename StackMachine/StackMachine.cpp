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
	auto res = *a - *b;
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
	auto res = *a / *b;
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
	auto res = *a % *b;
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

void StackMachine::parseInstructionsFromStream(std::istream &is)
{
	std::string line;
	int lineNum = 0;
	FactoryOperand fo;

	while (getline(is, line))
	{
		// Some parsing actions

		AddInstruction(
			Instruction(
			eInstructionType::push,
			fo.createOperand(eOperandType::Int8, "100"),
			line,
			lineNum
			)
		);

		lineNum++;
	}
}

