//
// Created by 17641238 on 24.03.2020.
//

#include "OInt32.h"

eOperandType OInt32::getType() const
{
	return eOperandType::Int32;
}

OInt32::OInt32(int32_t val)
{

}

int OInt32::getPrecision() const
{
	return 0;
}

IOperand const *OInt32::operator+(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt32::operator-(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt32::operator*(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt32::operator/(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OInt32::operator%(const IOperand& rhs) const
{
	return nullptr;
}

std::string const& OInt32::toString() const
{
	std::string s;
	return s;
}
