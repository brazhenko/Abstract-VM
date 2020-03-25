//
// Created by 17641238 on 24.03.2020.
//

#ifndef AVM_ODOUBLE_H
#define AVM_ODOUBLE_H

#include "IOperand/IOperand.h"

class ODouble : public IOperand
{
public:
	explicit ODouble(double val);
	explicit ODouble(const std::string &raw);
	[[nodiscard]] int getPrecision() const override ;
	[[nodiscard]] eOperandType  getType() const override;
	IOperand const* operator+(const IOperand& rhs) const override;
	IOperand const* operator-(const IOperand& rhs) const override;
	IOperand const* operator*(const IOperand& rhs) const override;
	IOperand const* operator/(const IOperand& rhs) const override;
	IOperand const* operator%(const IOperand& rhs) const override;
	[[nodiscard]] std::string const & toString() const override;
private:
	double value_;
	std::string raw_;
};

#endif //AVM_ODOUBLE_H
