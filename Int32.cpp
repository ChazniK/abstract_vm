/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/08 21:02:43 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32(void)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::Int32(Int32 const & src)
{
	std::cout << "Copy constructor with of: " << src.toString() << " type: " << src.getType() << std::endl;
}

Int32::Int32(const std::string numAsString, eOperandType type)
{
	this->_value = numAsString;
	this->_type = type;
	std::cout << "Constructor with of - value: " << " type: " << type << std::endl;
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
	return this->_type;
}

std::string const & Int32::toString( void ) const
{
	return this->_value;
}

IOperand const * Int32::operator+(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "adding\n";	
	long double result = a + b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int32_t>(result)));	
}

IOperand const * Int32::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "subtracting\n";	
	long double result = a - b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int32_t>(result)));
}
IOperand const * Int32::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "multiplying\n";	
	long double result = a * b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int32_t>(result)));
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "dividing\n";	
	long double result = a / b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int32_t>(result)));
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "modding\n";	
	long double result = std::fmod(a, b);
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int32_t>(result)));
}

Int32 & Int32::operator=(Int32 const & src)
{
	std::cout << "Int32 copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
		this->_type = src.getType();
	}
	return *this;
}

// IOperand const * Int32::checkOperand(eOperandType newType, long double result) const
// {
// 	OperandFactory fact;

// 	if (newType == INT8)
// 	{
// 		if (result < std::numeric_limits<int8_t>::min())
// 		{
// 			std::cout << "Underflow error" << std::endl;
// 		}
// 		else if ( result > std::numeric_limits<int8_t>::max())
// 		{
// 			std::cout << "Overflow error" << std::endl;
// 		}
// 		else
// 			return fact.createOperand(INT8, std::to_string(static_cast<int8_t>(result)));
// 	}
// 	else if (newType == INT16)
// 	{
// 		if (result < std::numeric_limits<int32_t>::min())
// 		{
// 			std::cout << "Underflow error" << std::endl;
// 		}
// 		else if ( result > std::numeric_limits<int32_t>::max())
// 		{
// 			std::cout << "Overflow error" << std::endl;
// 		}
// 		else
// 			return fact.createOperand(INT16, std::to_string(static_cast<int32_t>(result)));
// 	}
// 	else if (newType == INT32)
// 	{
// 		if (result < std::numeric_limits<int32_t>::min())
// 		{
// 			std::cout << "Underflow error" << std::endl;
// 		}
// 		else if ( result > std::numeric_limits<int32_t>::max())
// 		{
// 			std::cout << "Overflow error" << std::endl;
// 		}
// 		else
// 			return fact.createOperand(INT32, std::to_string(static_cast<int32_t>(result)));
// 	}
// 	else if (newType == FLOAT)
// 	{
// 		if (result < std::numeric_limits<float_t>::min())
// 		{
// 			std::cout << "Underflow error" << std::endl;
// 		}
// 		else if ( result > std::numeric_limits<float_t>::max())
// 		{
// 			std::cout << "Overflow error" << std::endl;
// 		}
// 		else
// 			return fact.createOperand(FLOAT, std::to_string(static_cast<float_t>(result)));
// 	}
// 	else if (newType == DOUBLE)
// 	{
// 		if (result < std::numeric_limits<double_t>::min())
// 		{
// 			std::cout << "Underflow error" << std::endl;
// 		}
// 		else if ( result > std::numeric_limits<double_t>::max())
// 		{
// 			std::cout << "Overflow error" << std::endl;
// 		}
// 		else
// 			return fact.createOperand(DOUBLE, std::to_string(static_cast<double_t>(result)));
// 	}
// 	return NULL;
// }