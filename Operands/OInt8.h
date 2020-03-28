//
// Created by 17641238 on 24.03.2020.
//

#ifndef AVM_OINT8_H
#define AVM_OINT8_H

#include "IOperand/IOperand.h"

class OInt8 : public IOperand
{
public:
	explicit OInt8(int8_t val);
	explicit OInt8(const std::string &raw);
	[[nodiscard]] int getPrecision() const override ;
	[[nodiscard]] eOperandType  getType() const override;
	IOperand const* operator+(const IOperand& rhs) const override;
	IOperand const* operator-(const IOperand& rhs) const override;
	IOperand const* operator*(const IOperand& rhs) const override;
	IOperand const* operator/(const IOperand& rhs) const override;
	IOperand const* operator%(const IOperand& rhs) const override;
	[[nodiscard]] std::string const & toString() const override;

private:
	int8_t value_;
	std::string raw_;
};

#endif //AVM_OINT8_H
