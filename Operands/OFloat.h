//
// Created by 17641238 on 24.03.2020.
//

#ifndef AVM_OFLOAT_H
#define AVM_OFLOAT_H

#include "IOperand/IOperand.h"

class OFloat : public IOperand
{
public:
public:
	explicit OFloat(float val);
	[[nodiscard]] int getPrecision() const override ;
	[[nodiscard]] eOperandType  getType() const override;
	IOperand const* operator+(const IOperand& rhs) const override;
	IOperand const* operator-(const IOperand& rhs) const override;
	IOperand const* operator*(const IOperand& rhs) const override;
	IOperand const* operator/(const IOperand& rhs) const override;
	IOperand const* operator%(const IOperand& rhs) const override;
	[[nodiscard]] std::string const & toString() const override;
private:
	float value_;
};

#endif //AVM_OFLOAT_H
