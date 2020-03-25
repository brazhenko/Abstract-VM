//
// Created by 17641238 on 24.03.2020.
//

#include "OInt8.h"

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
	return nullptr;
}

IOperand const *OInt8::operator-(const IOperand& rhs) const
{
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
	std::string k;
	return k;
}

int OInt8::getPrecision() const
{
	return -1;
}