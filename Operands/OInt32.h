//
// Created by 17641238 on 24.03.2020.
//

#ifndef AVM_OINT32_H
#define AVM_OINT32_H

#include "IOperand/IOperand.h"

class OInt32 : public IOperand
{
public:
	explicit OInt32(int32_t val);
	[[nodiscard]] int getPrecision() const override ;
	[[nodiscard]] eOperandType  getType() const override;
	IOperand const* operator+(const IOperand& rhs) const override;
	IOperand const* operator-(const IOperand& rhs) const override;
	IOperand const* operator*(const IOperand& rhs) const override;
	IOperand const* operator/(const IOperand& rhs) const override;
	IOperand const* operator%(const IOperand& rhs) const override;
	[[nodiscard]] std::string const & toString() const override;
private:
	int32_t value_;
};

#endif //AVM_OINT32_H
