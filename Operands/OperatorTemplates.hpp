#ifndef _AVM_OPERATOR_TEMPLATES_HPP
# define _AVM_OPERATOR_TEMPLATES_HPP

#include <IOperand/IOperand.h>
#include <sstream>
#include <Exceptions/AVMException.h>
#include <StackMachine.h>
#include "FactoryOperand.h"

template <typename T>
const IOperand*		getNewOperand(const IOperand& lhs, const IOperand& rhs)
{
	FactoryOperand fo;
	std::stringstream ssl(lhs.toString()), ssr(rhs.toString());

	T a, b;
	ssl >> a; ssr >> b;

	if ((b > 0) && (a > std::numeric_limits<T>::max() - b))
		/* `a + b` would overflow */
		throw AVM::ValueOverflow(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction(),
				rhs.toString()
		);

	if ((b < 0) && (a < std::numeric_limits<T>::min() - b))
		/* `a + b` would underflow */
		throw AVM::ValueUnderflow(
				StackMachine::Instance().getCurrentOperation()->getLineNum(),
				StackMachine::Instance().getCurrentOperation()->getInstruction(),
				rhs.toString()
		);

	std::stringstream res;
	res << a + b;


	return fo.createOperand(eOperandType::Int8, res.str());
}

# endif