/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:17:32 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/13 12:33:50 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int16.hpp"

Int16::Int16(void)
{
	std::cout << "Int16 constructor called" << std::endl;
}

Int16::Int16(const std::string numAsString, eOperandType type)
{
	long double t = stold(numAsString);
	if (t > INT16_MAX)
	{
		std::cout << "Int16 overflow" << std::endl;
		return;
	}
	else if (t < INT16_MIN)
	{
		std::cout << "Int16 underflow" << std::endl;
		return;
	}
	int16_t temp = static_cast<int16_t>(t);
	this->_value = std::to_string(temp);
	this->_type = type;
	// std::cout << "Constructor with of type: " << type << " value: " << numAsString << std::endl;
}

Int16::Int16(Int16 const & src)
{
	std::cout << "Int16 copy constructor called " << src.toString() << std::endl;
}

Int16::~Int16(void)
{
	std::cout << "Int16 destructor called" << std::endl;
}

int	Int16::getPrecision(void) const
{
	eOperandType precision = INT16;
	return precision;
}

eOperandType Int16::getType(void) const
{
	return this->_type;
}

std::string const & Int16::toString( void ) const
{
	return this->_value;
}

IOperand const * Int16::operator+(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a + b));
}

IOperand const * Int16::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a - b));
}

IOperand const * Int16::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a * b));
}

IOperand const * Int16::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a / b));
}

IOperand const * Int16::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(std::fmod(a, b)));
}

Int16 & Int16::operator=(Int16 const & src)
{
	std::cout << "Int16 copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
		this->_type = src.getType();
	}
	return *this;
}