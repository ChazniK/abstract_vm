/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/15 22:38:45 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"
#include "Error.hpp"

Int32::Int32(void)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::Int32(const std::string numAsString, eOperandType type)
{
	long double t = stold(numAsString);
	try
	{
		if (t > INT32_MAX)
		{
			throw Error::OverflowException();
		}
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	try 
	{
		if (t < INT32_MIN)
		{
			throw Error::UnderflowException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	int32_t temp = static_cast<int32_t>(t);
	this->_value = std::to_string(temp);
	this->_type = type;
	// std::cout << "Constructor with of type: " << type << " value: " << numAsString << std::endl;
}

Int32::Int32(Int32 const & src)
{
	std::cout << "Copy constructor with of: " << src.toString() << " type: " << src.getType() << std::endl;
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
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a + b));
}

IOperand const * Int32::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a - b));
}
IOperand const * Int32::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a * b));
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a / b));
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(std::fmod(a, b)));
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