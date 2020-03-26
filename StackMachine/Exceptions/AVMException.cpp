//
// Created by 17641238 on 26.03.2020.
//

#include "AVMException.h"
#include <sstream>
#include <iostream>

AVM::LexError::LexError(const int lineNum, const std::string& line)
{
	lineNum_ = lineNum;
	line_ = line;
}

const char *AVM::LexError::what() const throw()
{
	return exception::what();
}

AVM::SyntaxError::SyntaxError(int lineNum, const std::string& line,
		const std::string &Token)
{
	lineNum_ = lineNum;
	line_ = line;
	token_ = Token;

	std::stringstream ss;
	ss
			<< "Line " << lineNum_
			<< " : " << typeid(*this).name()
			<< " : " << line_
			<< " : " << token_;

	errMsg_ = ss.str();

}

const char *AVM::SyntaxError::what() const throw()
{
	return errMsg_.c_str();
}

AVM::InstructionUnknown::InstructionUnknown(const int lineNum,
		const std::string& instruction)
{
	lineNum_ = lineNum;
	instruction_ = instruction;
}

const char *AVM::InstructionUnknown::what() const throw()
{
	return exception::what();
}

const char *AVM::ValueOverflow::what() const throw()
{
	return exception::what();
}

const char *AVM::UnderflowValue::what() const throw()
{
	return exception::what();
}

const char *AVM::EmptyStack::what() const throw()
{
	return exception::what();
}

AVM::EmptyStack::EmptyStack(int lineNum, std::string& line)
{
	lineNum_ = lineNum;
	line_ = line;
}

const char *AVM::DivisionByZero::what() const throw()
{
	return exception::what();
}

AVM::DivisionByZero::DivisionByZero(int lineNum, std::string& instruction)
{
	lineNum_ = lineNum;
	line_ = instruction;
}

const char *AVM::NoExitInstruction::what() const throw()
{
	return exception::what();
}

AVM::NoExitInstruction::NoExitInstruction()
{

}

const char *AVM::AssertFailed::what() const throw()
{
	return exception::what();
}

AVM::AssertFailed::AssertFailed(int lineNum, std::string& line)
{
	lineNum_ = lineNum;
	line_ = line;
}

AVM::LessThanTwoValuesForBinExp::LessThanTwoValuesForBinExp(int lineNum,
		std::string& line)
{
	lineNum_ = lineNum;
	line_ = line;
}

const char *AVM::LessThanTwoValuesForBinExp::what() const throw()
{
	return exception::what();
}
