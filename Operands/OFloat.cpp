//
// Created by 17641238 on 24.03.2020.
//

#include "OFloat.h"

eOperandType OFloat::getType() const
{
	return eOperandType::Float;
}

OFloat::OFloat(float val)
{

}

int OFloat::getPrecision() const
{
	return 0;
}

IOperand const *OFloat::operator+(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OFloat::operator-(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OFloat::operator*(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OFloat::operator/(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *OFloat::operator%(const IOperand& rhs) const
{
	return nullptr;
}

std::string const& OFloat::toString() const
{
	std::string s;
	return s;
}
