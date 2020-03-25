//
// Created by 17641238 on 24.03.2020.
//

#include "OInt16.h"

eOperandType OInt16::getType() const
{
	return eOperandType::Int16;
}

OInt16::OInt16(int16_t val)
{

}

int OInt16::getPrecision() const
{
	return 0;
}

IOperand const *OInt16::operator+(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt16::operator-(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt16::operator*(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt16::operator/(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt16::operator%(const IOperand& rhs) const
{
	return nullptr;
}

std::string const& OInt16::toString() const
{
	std::string s;
	return s;
}
