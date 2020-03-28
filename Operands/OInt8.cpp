//
// Created by 17641238 on 24.03.2020.
//

#include "OInt8.h"
#include "FactoryOperand.h"
#include <sstream>
#include <StackMachine.h>
#include <Exceptions/AVMException.h>
#include <climits>
#include <iostream>
#include <cfloat>
#include <cfenv>

OInt8::OInt8(int8_t val)
{
	value_ = val;
}

eOperandType OInt8::getType() const
{
	return eOperandType::Int8;
}

IOperand const* OInt8::operator+(const IOperand& rhs) const
{
	FactoryOperand fo;
	std::stringstream ssl(toString()), ssr(rhs.toString());

	switch (rhs.getType())
	{
	case eOperandType::Int8:
	{
		std::cerr << "eOperandType::Int8" << std::endl;
		int16_t a, b;
		ssl >> a; ssr >> b;

		if ((b > 0) && (a > std::numeric_limits<int8_t>::max() - b))
			/* `a + b` would overflow */
			throw AVM::ValueOverflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
					);

		if ((b < 0) && (a < std::numeric_limits<int8_t>::min() - b))
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
	case eOperandType::Int16:
	{
		std::cerr << "eOperandType::Int16" << std::endl;
		int16_t a, b;
		ssl >> a; ssr >> b;

		if ((b > 0) && (a > std::numeric_limits<int16_t>::max() - b))
			/* `a + b` would overflow */
			throw AVM::ValueOverflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		if ((b < 0) && (a < std::numeric_limits<int16_t>::min() - b))
			/* `a + b` would underflow */
			throw AVM::ValueUnderflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		std::stringstream res;
		res << a + b;
		return fo.createOperand(eOperandType::Int16, res.str());
	}
	case eOperandType::Int32:
	{
		std::cerr << "eOperandType::Int32" << std::endl;
		int32_t a, b;
		ssl >> a; ssr >> b;

		if ((b > 0) && (a > std::numeric_limits<int32_t>::max() - b))
			/* `a + b` would overflow */
			throw AVM::ValueOverflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		if ((b < 0) && (a < std::numeric_limits<int32_t>::min() - b))
			/* `a + b` would underflow */
			throw AVM::ValueUnderflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		std::stringstream res;
		res << a + b;
		return fo.createOperand(eOperandType::Int32, res.str());
	}
	case eOperandType::Float:
	{
		float a, b;
		ssl >> a; ssr >> b;

		if ((b > 0) && (a > std::numeric_limits<float>::max() - b))
			/* `a + b` would overflow */
			throw AVM::ValueOverflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		if ((b < 0) && (a < std::numeric_limits<float>::min() - b))
			/* `a + b` would underflow */
			throw AVM::ValueUnderflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		std::stringstream res;
		res << a + b;
		return fo.createOperand(eOperandType::Float, res.str());
	}
	case eOperandType::Double:
	{
		double a, b;
		ssl >> a; ssr >> b;

		if ((b > 0) && (a > std::numeric_limits<double >::min() - b))
			/* `a + b` would overflow */
			throw AVM::ValueOverflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		if ((b < 0) && (a < std::numeric_limits<double>::min() - b))
			/* `a + b` would underflow */
			throw AVM::ValueUnderflow(
					StackMachine::Instance().getCurrentOperation()->getLineNum(),
					StackMachine::Instance().getCurrentOperation()->getInstruction(),
					rhs.toString()
			);

		std::stringstream res;
		res << a + b;
		return fo.createOperand(eOperandType::Double, res.str());
	}
	case eOperandType::None:
	{
		// TODO
	}
	}
	return nullptr;
}

IOperand const *OInt8::operator-(const IOperand& rhs) const
{
	FactoryOperand fo;
	return nullptr;
}

IOperand const *OInt8::operator*(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt8::operator/(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt8::operator%(const IOperand& rhs) const
{
	return nullptr;
}

std::string const& OInt8::toString() const
{
	return raw_;
}

int OInt8::getPrecision() const
{
	return static_cast<int>(getType());
}

OInt8::OInt8(const std::string &raw)
{
	std::stringstream ss(raw);
	ss >> value_;
	raw_ = raw;
}
