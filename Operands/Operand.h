//
// Created by 17641238 on 25.03.2020.
//

#ifndef AVM_OPERAND_H
#define AVM_OPERAND_H

#include "IOperand.h"

template <typename T>
class Operand : public IOperand
{
public:
	[[nodiscard]] eOperandType getType() const override;
private:
	T value_;
};

#endif //AVM_OPERAND_H
