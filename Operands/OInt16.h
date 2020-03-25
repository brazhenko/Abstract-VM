//
// Created by 17641238 on 24.03.2020.
//

#ifndef AVM_OINT16_H
#define AVM_OINT16_H

#include "IOperand/IOperand.h"

class OInt16 : public IOperand
{
public:
	explicit OInt16(int16_t val);
	[[nodiscard]] int getPrecision() const override ;
	[[nodiscard]] eOperandType  getType() const override;
	IOperand const* operator+(const IOperand& rhs) const override;
	IOperand const* operator-(const IOperand& rhs) const override;
	IOperand const* operator*(const IOperand& rhs) const override;
	IOperand const* operator/(const IOperand& rhs) const override;
	IOperand const* operator%(const IOperand& rhs) const override;
	[[nodiscard]] std::string const & toString() const override;

private:
	int16_t value_;
};

#endif //AVM_OINT16_H
