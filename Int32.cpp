/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/03 23:51:05 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32(void)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::Int32(Int32 const & src)
{
	std::cout << "Int32 copy constructor called " << src.getValue() << std::endl;
}

Int32::Int32(const std::string numAsString)
{
	this->_value = std::stoi(numAsString);
	std::cout << "Constructor with of type int32 - value: " << getValue() << std::endl;
}

Int32::~Int32(void)
{
	std::cout << "Int32 destructor called" << std::endl;
}

int	Int32::getPrecision(void) const
{	
	eOperandType precision = INT32;
	return precision;
}

eOperandType Int32::getType(void) const
{
	return ::INT32;
}

int32_t Int32::getValue(void) const
{
	return this->_value;
}

Int32::operator int(void)
{
	return this->_value;
}

/*
Int32::operator double(void)
{
	return static_cast<double>(this->_value);
}
*/
IOperand const * Int32::operator+(IOperand const & rhs) const
{
	double					lhsVal;
	double					rhsVal;
	double					result;
	std::stringstream		ss;
	IOperand				*ret;

	lhsVal = std::strtod(this->StringValue.c_str(), 0);
	rhsVal = std::strtod(rhs.StringValue.c_str(), 0);
	result = lhsVal + rhsVal;
	ss << result;
	if (getType() < rhs.getType())
	{
		return 
	}
	else
	{
		return (IOperandController::Instance().createOperand(this->getType(),  ss.str()));
	}
	return (ret);
}

IOperand const * IOperandController::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const *RetOperand = (*this.*OperandFt[type])(value);
	return (RetOperand);
}

IOperand const * IOperandController::createInt32( std::string const & value ) const
{
	class Int32			*retOperand = new class Int32();
	double				retVal;

	retOperand->StringValue = value;
	retVal = std::strtod(value.c_str(), 0);
	//std::cout << "creating int16" << std::endl;
	if (retVal > 2147483647)
	{
		throw ValueOverflow("Error: Int32 Value overflow");
	}
	else if (retVal < -2147483648)
	{
		throw ValueUnderflow("Error: Int32 Value underflow");
	}
	return (retOperand);
}

/*IOperand const * Int32::operator-(IOperand const & rhs) const
{
	return Int32(getValue() - rhs.getValue());
}

IOperand const * Int32::operator*(IOperand const & rhs) const
{
	return IOperand(getValue() * rhs.getValue());
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	return IOperand(getValue() / rhs.getValue());
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	return IOperand(getValue() % rhs.getValue());
}*/

std::string const & Int32::toString( void ) const
{
	this->
}

// Int32 & Int32::operator=(Int32 const & src)
// {
// 	std::cout << "Int32 copy constructor called" << std::endl;
// 	if (this != &src)
// 	{
// 		this->_value = src.getValue();
// 	}
// 	return *this;
// }
