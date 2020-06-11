//
// Created by 17641238 on 26.03.2020.
//

#include "AVMException.h"
#include <sstream>

AVM::LexError::LexError(const int lineNum, const std::string& line, char c)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "LexError"
			<< " : " << line
			<< " : " << c;

	errMsg_ = ss.str();
}

const char *AVM::LexError::what() const throw()
{
	return errMsg_.c_str();
}

AVM::SyntaxError::SyntaxError(int lineNum, const std::string& line,
		const std::string &Token)
{
	std::stringstream ss;
	ss
			<< "Line " << lineNum
			<< " : " << "SyntaxError"
			<< " : " << line
			<< " : " << Token;

	errMsg_ = ss.str();

}

const char *AVM::SyntaxError::what() const throw()
{
	return errMsg_.c_str();
}

AVM::InstructionUnknown::InstructionUnknown(const int lineNum,
		const std::string& line,
		const std::string& instruction)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "InstructionUnknown"
			<< " : " << line
			<< " : " << instruction;

	errMsg_ = ss.str();
}

const char *AVM::InstructionUnknown::what() const throw()
{
	return errMsg_.c_str();
}

AVM::ValueOverflow::ValueOverflow(int lineNum, const std::string& line,
		const std::string& value)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "ValueOverflow"
			<< " : " << line
			<< " : " << value;

	errMsg_ = ss.str();
}

const char *AVM::ValueOverflow::what() const throw()
{
	return errMsg_.c_str();
}

AVM::ValueUnderflow::ValueUnderflow(int lineNum, const std::string& line,
		const std::string& value)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "ValueUnderflow"
			<< " : " << line
			<< " : " << value;

	errMsg_ = ss.str();
}

const char *AVM::ValueUnderflow::what() const throw()
{
	return errMsg_.c_str();
}

AVM::EmptyStack::EmptyStack(int lineNum, const std::string& line)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "EmptyStack"
			<< " : " << line;

	errMsg_ = ss.str();
}


const char *AVM::EmptyStack::what() const throw()
{
	return errMsg_.c_str();
}

AVM::DivisionByZero::DivisionByZero(int lineNum, const std::string& instruction)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "DivisionByZero"
			<< " : " << instruction;

	errMsg_ = ss.str();
}

const char *AVM::DivisionByZero::what() const throw()
{
	return errMsg_.c_str();
}

AVM::NoExitInstruction::NoExitInstruction()
{
	std::stringstream ss;

	ss
			<< "Error : NoExitInstruction";

	errMsg_ = ss.str();
}

const char *AVM::NoExitInstruction::what() const throw()
{
	return errMsg_.c_str();
}

AVM::AssertFailed::AssertFailed(int lineNum, const std::string& line)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "AssertFailed"
			<< " : " << line;

	errMsg_ = ss.str();
}

const char *AVM::AssertFailed::what() const throw()
{
	return errMsg_.c_str();
}

AVM::LessThanTwoValuesForBinExp::LessThanTwoValuesForBinExp(int lineNum,
		const std::string& line)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "LessThanTwoValuesForBinExp"
			<< " : " << line;

	errMsg_ = ss.str();
}

const char *AVM::LessThanTwoValuesForBinExp::what() const throw()
{
	return errMsg_.c_str();
}

AVM::InvalidOperandsForBinExp::InvalidOperandsForBinExp(int lineNum,
		const std::string& line)
{
	std::stringstream ss;

	ss
			<< "Line " << lineNum
			<< " : " << "LessThanTwoValuesForBinExp"
			<< " : " << line;

	errMsg_ = ss.str();
}

const char *AVM::InvalidOperandsForBinExp::what() const throw()
{
	return errMsg_.c_str();
}

AVM::OptionRequiresAnArguement::OptionRequiresAnArguement(char c)
{
	std::stringstream ss;

	ss << "Option -" << c << " requires an argument.";
	errMsg_ = ss.str();
}

const char *AVM::OptionRequiresAnArguement::what() const throw()
{
	return errMsg_.c_str();
}

AVM::UnknownOption::UnknownOption(int c)
{
	std::stringstream ss;

	if (std::isprint(c))
		ss << "Unknown option - " << (char)c;
	else
		ss << "Unknown option - " << std::hex << c;

	errMsg_ = ss.str();
}

const char *AVM::UnknownOption::what() const throw()
{
	return errMsg_.c_str();
}

AVM::DoubleSemiColonFound::DoubleSemiColonFound()
{
	std::stringstream ss;

	ss  << "Empty\n";
	errMsg_ = ss.str();
}
