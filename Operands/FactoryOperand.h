//
// Created by 17641238 on 25.03.2020.
//

#ifndef AVM_FACTORYOPERAND_H
#define AVM_FACTORYOPERAND_H

#include <IOperand/IOperand.h>

class FactoryOperand
{
public:
	[[nodiscard]] const IOperand* createOperand(eOperandType type, const std::string& value) const;

private:
	[[nodiscard]] const IOperand* createInt8(const std::string& value) const;
	[[nodiscard]] const IOperand* createInt16(const std::string& value) const;
	[[nodiscard]] const IOperand* createInt32(const std::string& value) const;
	[[nodiscard]] const IOperand* createFloat(const std::string& value) const;
	[[nodiscard]] const IOperand* createDouble(const std::string& value) const;
};

#endif //AVM_FACTORYOPERAND_H
