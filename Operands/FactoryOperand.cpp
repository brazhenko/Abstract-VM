//
// Created by 17641238 on 25.03.2020.
//

#include <sstream>
#include "FactoryOperand.h"
#include "OInt8.h"

const IOperand *
FactoryOperand::createOperand(eOperandType type, const std::string& value) const
{
	switch (type)
	{
	case eOperandType::Int8:
		return createInt8(value);
	case eOperandType::Int16:
		return createInt16(value);
	case eOperandType::Int32:
		return createInt32(value);
	case eOperandType::Float:
		return createFloat(value);
	case eOperandType::Double:
		return createDouble(value);
	}
}

const IOperand *FactoryOperand::createInt8(const std::string& value) const
{
	int8_t val;

	std::stringstream ss(value);
	ss >> val;
	IOperand* ptr = new OInt8(val);
	return ptr;
}

const IOperand *FactoryOperand::createInt16(const std::string& value) const
{
	return nullptr;
}

const IOperand *FactoryOperand::createInt32(const std::string& value) const
{
	return nullptr;
}

const IOperand *FactoryOperand::createFloat(const std::string& value) const
{
	return nullptr;
}

const IOperand *FactoryOperand::createDouble(const std::string& value) const
{
	return nullptr;
}
