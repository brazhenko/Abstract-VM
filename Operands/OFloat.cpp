//
// Created by 17641238 on 24.03.2020.
//

#include "OFloat.h"
#include <sstream>

eOperandType OFloat::getType() const
{
	return eOperandType::Float;
}

OFloat::OFloat(float val)
{

}

int OFloat::getPrecision() const
{
	return static_cast<int>(getType());
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
	return raw_;
}

OFloat::OFloat(const std::string &raw)
{
	std::stringstream ss(raw);
	ss >> value_;
	raw_ = raw;
}
