//
// Created by 17641238 on 25.03.2020.
//

#ifndef AVM_OPERAND_H
#define AVM_OPERAND_H

#include <sstream>
#include "IOperand.h"
#include "OperatorTemplates.hpp"


static eOperandType getTypeMaxPrec(const IOperand& lhs,
		const IOperand& rhs);

template <typename T>
static const IOperand*		getOpSum(const IOperand& lhs,
		const IOperand& rhs,
		eOperandType resOpType);

template <typename T>
static const IOperand*		getOpDiff(const IOperand& lhs,
		const IOperand& rhs,
		eOperandType resOpType);

template <typename T, eOperandType OP>
class Operand : public IOperand
{
public:
	explicit Operand(const std::string& raw);
	[[nodiscard]] int getPrecision() const override ;
	[[nodiscard]] eOperandType getType() const override;
	IOperand const* operator+(const IOperand& rhs) const override;
	IOperand const* operator-(const IOperand& rhs) const override;
	IOperand const* operator*(const IOperand& rhs) const override;
	IOperand const* operator/(const IOperand& rhs) const override;
	IOperand const* operator%(const IOperand& rhs) const override;
	[[nodiscard]] std::string const & toString() const override;

private:
	const eOperandType type_;
	const std::string raw_;
};

template <typename T, eOperandType OP>
Operand<T, OP>::Operand(const std::string& raw)
		: type_(OP), raw_(raw)
{}

template <typename T, eOperandType OP>
eOperandType Operand<T, OP>::getType() const
{
	return type_;
}

template <typename T, eOperandType OP>
IOperand const *Operand<T, OP>::operator+(const IOperand& rhs) const
{
	eOperandType retType = getTypeMaxPrec(*this, rhs);

	switch (retType)
	{
	case eOperandType::Int8:
		return getOpSum<int16_t>(*this, rhs, retType);
	case eOperandType::Int16:
		return getOpSum<int16_t>(*this, rhs, retType);
	case eOperandType::Int32:
		return getOpSum<int32_t>(*this, rhs, retType);
	case eOperandType::Float:
		return getOpSum<float>(*this, rhs, retType);
	case eOperandType::Double:
		return getOpSum<double>(*this, rhs, retType);
	default:
		return nullptr;
	}
}

template <typename T, eOperandType OP>
IOperand const *Operand<T, OP>::operator-(const IOperand& rhs) const
{
	eOperandType retType = getTypeMaxPrec(*this, rhs);

	switch (retType)
	{
	case eOperandType::Int8:
		return getOpDiff<int16_t>(*this, rhs, retType);
	case eOperandType::Int16:
		return getOpDiff<int16_t>(*this, rhs, retType);
	case eOperandType::Int32:
		return getOpDiff<int32_t>(*this, rhs, retType);
	case eOperandType::Float:
		return getOpDiff<float>(*this, rhs, retType);
	case eOperandType::Double:
		return getOpDiff<double>(*this, rhs, retType);
	default:
		return nullptr;
	}
}

template <typename T, eOperandType OP>
IOperand const *Operand<T, OP>::operator*(const IOperand& rhs) const
{
	return nullptr;
}

template <typename T, eOperandType OP>
IOperand const *Operand<T, OP>::operator/(const IOperand& rhs) const
{
	return nullptr;
}

template <typename T, eOperandType OP>
IOperand const *Operand<T, OP>::operator%(const IOperand& rhs) const
{
	return nullptr;
}

template <typename T, eOperandType OP>
std::string const& Operand<T, OP>::toString() const
{
	return raw_;
}

template<typename T, eOperandType OP>
int Operand<T, OP>::getPrecision() const
{
	return static_cast<int>(getType());
}

//------------------------------------------------------------------------------

template <typename T>
static const IOperand*		getOpSum(const IOperand& lhs,
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

static eOperandType getTypeMaxPrec(const IOperand& lhs,
		const IOperand& rhs)
{

	if (lhs.getPrecision() > rhs.getPrecision())
		return lhs.getType();
	return rhs.getType();
}

template <typename T>
static const IOperand*		getOpDiff(const IOperand& lhs,
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
	res << a - b;

	return fo.createOperand(resOpType, res.str());
}

#endif //AVM_OPERAND_Hч
