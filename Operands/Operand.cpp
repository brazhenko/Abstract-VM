//****************************
// CLASS TEMPLATE DEFINITION
//****************************

#include "Operand.hpp"
#include "Exceptions/AVMException.h"
#include "FactoryOperand.h"

template<class T> void add_flow_check(T a, T b) {
	T sum = a + b;
	if ((a < 0) == (b < 0)) {
		if (a < 0 && sum > b) throw AVM::ValueUnderflow(1, "ValueUnderflow", "Unknown");
		else if (sum < b) throw AVM::ValueOverflow(1, "ValueUnderflow", "Unknown");
	}
}
template<class T> void mul_flow_check(T a, T b) {
	T max = std::numeric_limits<T>::max();
	T abs_a = (a < 0 ? a * -1 : a);
	T abs_b = (b < 0 ? b * -1 : b);
	if (abs_a > max/abs_b) {
		if ((a < 0) && (b < 0)) throw AVM::ValueOverflow(1, "ValueUnderflow", "Unknown");
		else if ((a > 0) && (b > 0)) throw AVM::ValueOverflow(1, "ValueUnderflow", "Unknown");
		else throw AVM::ValueUnderflow(1, "ValueUnderflow", "Unknown");
	}
}

template<class T> Operand<T>::Operand( void ) { this->_value = std::to_string(static_cast<T>(0)); }
template<class T> Operand<T>::Operand( Operand<T> const & obj ) { *this = obj; }
template<class T> Operand<T>::~Operand( void ) {}
template<class T> Operand<T> & Operand<T>::operator=( Operand<T> const & rhs ) { this->_value = rhs._value; return *this; }

template<class T> Operand<T>::Operand( T value ) { this->_value = std::to_string(value); }
template<class T> Operand<T>::Operand( std::string str ) { this->_value = std::to_string(static_cast<T>(stod(str))); }

template<class T> IOperand const * Operand<T>::operator+( IOperand const & rhs ) const {
	if (this->getPrecision() < rhs.getPrecision()) return (rhs + *this);
	T lhs_value = static_cast<T>(stod(this->_value));
	T rhs_value = static_cast<T>(stod(rhs.toString()));
	add_flow_check<T>(lhs_value, rhs_value);
	OperandFactory * factory = new OperandFactory();
	IOperand const * ret_val = factory->createOperand(this->getType(), std::to_string(static_cast<T>(stod(this->_value)) + rhs_value));
	delete factory;
	return ret_val;
}
template<class T> IOperand const * Operand<T>::operator-( IOperand const & rhs ) const {
	if (this->getPrecision() < rhs.getPrecision()) return (rhs - *this);
	T lhs_value = static_cast<T>(stod(this->_value));
	T rhs_value = static_cast<T>(stod(rhs.toString()));
	add_flow_check<T>(lhs_value, rhs_value * -1);
	OperandFactory * factory = new OperandFactory();
	IOperand const * ret_val = factory->createOperand(this->getType(), std::to_string(lhs_value - rhs_value));
	delete factory;
	return ret_val;
}
template<class T> IOperand const * Operand<T>::operator*( IOperand const & rhs ) const {
	if (this->getPrecision() < rhs.getPrecision()) return (rhs * *this);
	T lhs_value = static_cast<T>(stod(this->_value));
	T rhs_value = static_cast<T>(stod(rhs.toString()));
	mul_flow_check<T>(lhs_value, rhs_value);
	OperandFactory * factory = new OperandFactory();
	IOperand const * ret_val = factory->createOperand(this->getType(), std::to_string(lhs_value * rhs_value));
	delete factory;
	return ret_val;
}
template<class T> IOperand const * Operand<T>::operator/( IOperand const & rhs ) const {
	double lhs_value = stod(this->toString());
	double rhs_value  = stod(rhs.toString());
	if (rhs_value == 0) throw AVM::DivisionByZero(1, "DivisionByZero");;
	eOperandType final_type = (this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType());
	OperandFactory * factory = new OperandFactory();
	IOperand const * ret_val = factory->createOperand(final_type, std::to_string(lhs_value / rhs_value));
	delete factory;
	return ret_val;
}
template<class T> IOperand const * Operand<T>::operator%( IOperand const & rhs ) const {
	long lhs_value = stol(this->toString());
	long rhs_value  = stol(rhs.toString());
	if (rhs_value == 0) throw AVM::DivisionByZero(1, "DivisionByZero");;
	eOperandType final_type = (this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType());
	OperandFactory * factory = new OperandFactory();
	IOperand const * ret_val = factory->createOperand(final_type, std::to_string(lhs_value % rhs_value));
	delete factory;
	return ret_val;
}

template<class T> std::string const & Operand<T>::toString( void ) const {
	return this->_value;
}

//****************************
// CLASS TEMPLATE SPECIALIZATION
//****************************

template<> int			Operand<int8_t>::getPrecision( void ) const		{ return Int8; }
template<> eOperandType	Operand<int8_t>::getType( void ) const			{ return Int8; }

template<> int			Operand<int16_t>::getPrecision( void ) const	{ return Int16; }
template<> eOperandType	Operand<int16_t>::getType( void ) const			{ return Int16; }

template<> int			Operand<int32_t>::getPrecision( void ) const	{ return Int32; }
template<> eOperandType	Operand<int32_t>::getType( void ) const			{ return Int32; }

template<> int			Operand<float>::getPrecision( void ) const		{ return Float; }
template<> eOperandType	Operand<float>::getType( void ) const			{ return Float; }

template<> int			Operand<double>::getPrecision( void ) const		{ return Double; }
template<> eOperandType	Operand<double>::getType( void ) const			{ return Double; }

//****************************
// CLASS TEMPLATE HARD DECLARATION
//****************************

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;