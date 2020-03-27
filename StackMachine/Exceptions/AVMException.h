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
	{};

	class LexError : public Exception
	{
	public:
		LexError(int lineNum, const std::string &line, char c);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};

	class SyntaxError : public Exception
	{
	public:
		SyntaxError(int lineNum, const std::string &line, const std::string& token);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};

	class InstructionUnknown : public Exception
	{
	public:
		InstructionUnknown(int lineNum,
				const std::string& line,
				const std::string &instruction);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};

	class ValueOverflow : public Exception
	{
	public:
		ValueOverflow(int lineNum,
				const std::string& line,
				const std::string& value);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};

	class ValueUnderflow : public Exception
	{
	public:
		ValueUnderflow(int lineNum,
				const std::string& line,
				const std::string& value);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};

	class EmptyStack : public Exception
	{
	public:
		EmptyStack(int lineNum, const std::string& line);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};

	class DivisionByZero : public Exception
	{
	public:
		DivisionByZero(int lineNum, std::string& instruction);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};

	class NoExitInstruction : public Exception
	{
	public:
		NoExitInstruction();
		[[nodiscard]] const char *what() const throw() override;

	private:
		std::string errMsg_;
	};

	class AssertFailed : public Exception
	{
	public:
		AssertFailed(int lineNum, std::string &line);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;

	};

	class LessThanTwoValuesForBinExp : public Exception
	{
	public:
		LessThanTwoValuesForBinExp(int lineNum, std::string &line);
		[[nodiscard]] const char *what() const throw() override;
	private:
		std::string errMsg_;
	};
}

#endif //AVM_AVMEXCEPTION_H
