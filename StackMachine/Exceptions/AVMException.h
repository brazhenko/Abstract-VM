//
// Created by 17641238 on 26.03.2020.
//

#ifndef AVM_AVMEXCEPTION_H
#define AVM_AVMEXCEPTION_H

#include <exception>
#include <string>

namespace AVM
{
	class Exception : public std::exception
	{
	public:
		std::string errMsg_;
	};

	class LexError : public Exception
	{
	public:
		LexError(int lineNum, const std::string &line, char c);
		[[nodiscard]] const char *what() const throw() override;
	};

	class SyntaxError : public Exception
	{
	public:
		SyntaxError(int lineNum, const std::string &line, const std::string& token);
		[[nodiscard]] const char *what() const throw() override;
	};

	class InstructionUnknown : public Exception
	{
	public:
		InstructionUnknown(int lineNum,
				const std::string& line,
				const std::string &instruction);
		[[nodiscard]] const char *what() const throw() override;
	};

	class ValueOverflow : public Exception
	{
	public:
		ValueOverflow(int lineNum,
				const std::string& line,
				const std::string& value);
		[[nodiscard]] const char *what() const throw() override;
	};

	class ValueUnderflow : public Exception
	{
	public:
		ValueUnderflow(int lineNum,
				const std::string& line,
				const std::string& value);
		[[nodiscard]] const char *what() const throw() override;
	};

	class EmptyStack : public Exception
	{
	public:
		EmptyStack(int lineNum, const std::string& line);
		[[nodiscard]] const char *what() const throw() override;
	};

	class DivisionByZero : public Exception
	{
	public:
		DivisionByZero(int lineNum, const std::string& instruction);
		[[nodiscard]] const char *what() const throw() override;
	};

	class NoExitInstruction : public Exception
	{
	public:
		NoExitInstruction();
		[[nodiscard]] const char *what() const throw() override;

	};

	class AssertFailed : public Exception
	{
	public:
		AssertFailed(int lineNum, const std::string &line);
		[[nodiscard]] const char *what() const throw() override;

	};

	class LessThanTwoValuesForBinExp : public Exception
	{
	public:
		LessThanTwoValuesForBinExp(int lineNum, const std::string& line);
		[[nodiscard]] const char *what() const throw() override;
	};

	class InvalidOperandsForBinExp : public Exception
	{
	public:
		InvalidOperandsForBinExp(int lineNum, const std::string& line);
		[[nodiscard]] const char *what() const throw() override;
	};

	class OptionRequiresAnArguement : public Exception
	{
	public:
		explicit OptionRequiresAnArguement(char c);
		[[nodiscard]] const char *what() const throw() override;
	};

	class UnknownOption : public Exception
	{
	public:
		explicit UnknownOption(int c);
		[[nodiscard]] const char *what() const throw() override;
	};

	class NeedHelp : public Exception
	{};

	class DoubleSemiColonFound : public Exception
	{
	public:
		explicit DoubleSemiColonFound();
	};

}

#endif //AVM_AVMEXCEPTION_H
