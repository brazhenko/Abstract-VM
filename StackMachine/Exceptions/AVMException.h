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
		LexError(int lineNum, const std::string &line);
		const char *what() const throw();
	private:
		int lineNum_;
		std::string line_;
		std::string errMsg_;
	};

	class SyntaxError : public Exception
	{
	public:
		SyntaxError(int lineNum, const std::string &line, const std::string& token);
		const char *what() const throw();
	private:
		int lineNum_;
		std::string line_;
		std::string token_;
		std::string errMsg_;
	};

	class InstructionUnknown : public Exception
	{
	public:
		InstructionUnknown(int lineNum, const std::string &instruction);
		const char *what() const throw();
	private:
		int lineNum_;
		std::string instruction_;
		std::string errMsg_;
	};

	class ValueOverflow : public Exception
	{
	public:
		const char *what() const throw();
	};

	class UnderflowValue : public Exception
	{
	public:
		const char *what() const throw();
	};

	class EmptyStack : public Exception
	{
	public:
		EmptyStack(int lineNum, std::string& line);
		const char *what() const throw();
	private:
		int lineNum_;
		std::string line_;
		std::string errMsg_;
	};

	class DivisionByZero : public Exception
	{
	public:
		DivisionByZero(int lineNum, std::string& instruction);
		const char *what() const throw();
	private:
		int lineNum_;
		std::string line_;
		std::string errMsg_;
	};

	class NoExitInstruction : public Exception
	{
	public:
		NoExitInstruction();
		const char *what() const throw();
	};

	class AssertFailed : public Exception
	{
	public:
		AssertFailed(int lineNum, std::string &line);
		const char *what() const throw();
	private:
		int lineNum_;
		std::string line_;
		std::string errMsg_;

	};

	class LessThanTwoValuesForBinExp : public Exception
	{
	public:
		LessThanTwoValuesForBinExp(int lineNum, std::string &line);
		const char *what() const throw();
	private:
		int lineNum_;
		std::string line_;
		std::string errMsg_;

	};
}




#endif //AVM_AVMEXCEPTION_H
