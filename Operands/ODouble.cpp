//
// Created by 17641238 on 24.03.2020.
//

#include "ODouble.h"

eOperandType ODouble::getType() const
{
	return eOperandType::Double;
}

ODouble::ODouble(double val)
{

}

int ODouble::getPrecision() const
{
	return 0;
}

IOperand const *ODouble::operator+(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *ODouble::operator-(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *ODouble::operator*(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *ODouble::operator/(const IOperand& rhs) const
{
	return nullptr;
}

IOperand const *ODouble::operator%(const IOperand& rhs) const
{
	return nullptr;
}

std::string const& ODouble::toString() const
{
	std::string s;
	return s;
}
