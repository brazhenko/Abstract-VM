//
// Created by 17641238 on 24.03.2020.
//

#include "ODouble.h"
#include "FactoryOperand.h"
#include <sstream>

eOperandType ODouble::getType() const
{
	return eOperandType::Double;
}

ODouble::ODouble(double val)
{

}

int ODouble::getPrecision() const
{
	return static_cast<int>(getType());
}

IOperand const *ODouble::operator+(const IOperand& rhs) const
{
	std::stringstream ss;
	FactoryOperand fo;


	if (getPrecision() == rhs.getPrecision() ||
			getPrecision() > rhs.getPrecision())
	{
		return 	fo.createOperand(getType(), ss.str());
	}
	else
	{
		return 	fo.createOperand(getType(), ss.str());
	}
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
	return raw_;
}

ODouble::ODouble(const std::string &raw)
{
	std::stringstream ss(raw);
	ss >> value_;
	raw_ = raw;
}
