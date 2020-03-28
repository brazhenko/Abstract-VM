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

#include "OperatorTemplates.hpp"


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

	if (getPrecision() > rhs.getPrecision())
		return f(*this, rhs, getType());
	else
		return f(*this, rhs, rhs.getType());

	NoneType
	{
		// TODO
	}
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
