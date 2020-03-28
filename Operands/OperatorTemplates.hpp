#ifndef _AVM_OPERATOR_TEMPLATES_HPP
# define _AVM_OPERATOR_TEMPLATES_HPP

#include <IOperand/IOperand.h>
#include <sstream>
#include <Exceptions/AVMException.h>
#include <StackMachine.h>
#include "FactoryOperand.h"

template <typename T>
const IOperand*		getOpSum(const IOperand& lhs,
		const IOperand& rhs,
		eOperandType resOpType);

template <typename T>
const IOperand*   f(const IOperand& lhs,
		const IOperand& rhs,
		eOperandType t);

template <typename T>
const IOperand*		getOpSum(const IOperand& lhs,
					const IOperand& rhs,
					eOperandType resOpType)
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

	return fo.createOperand(resOpType, res.str());
}

const IOperand*   f(const IOperand& lhs,
		const IOperand& rhs,
		eOperandType t)
{
	switch (t)
	{
	case eOperandType::Int8:
		return getOpSum<int16_t>(lhs, rhs, eOperandType::Int8);
	case eOperandType::Int16:
		return getOpSum<int16_t>(lhs, rhs, eOperandType::Int16);
	case eOperandType::Int32:
		return getOpSum<int32_t>(lhs, rhs, eOperandType::Int32);
	case eOperandType::Float:
		return getOpSum<float>(lhs, rhs, eOperandType::Float);
	case eOperandType::Double:
		return getOpSum<double>(lhs, rhs, eOperandType::Double);
	}
}

# endif