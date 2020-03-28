//
// Created by 17641238 on 22.03.2020.
//

#ifndef AVM_IOPERAND_H
#define AVM_IOPERAND_H

#include <string>

enum class eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double,
	None
};

class IOperand
{
public:
	[[nodiscard]] virtual int getPrecision() const = 0;
	// Precision of the type of the instance
	[[nodiscard]] virtual eOperandType  getType() const = 0;
	// Type of the instance
	virtual IOperand const* operator+(const IOperand& rhs) const = 0;
	// Sum
	virtual IOperand const* operator-(const IOperand& rhs) const = 0;
	// Difference
	virtual IOperand const* operator*(const IOperand& rhs) const = 0;
	// Product
	virtual IOperand const* operator/(const IOperand& rhs) const = 0;
	// Quotient
	virtual IOperand const* operator%(const IOperand& rhs) const = 0;
	// Modulo
	[[nodiscard]] virtual std::string const & toString() const = 0;
	// String representation of the instance
	virtual ~IOperand() = default;
};

#endif //AVM_IOPERAND_H
