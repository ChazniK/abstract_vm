/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:08:52 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/13 18:57:23 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"

Int8::Int8(void)
{
	std::cout << "Int8 constructor called" << std::endl;
}

Int8::Int8(Int8 const & src)
{
	std::cout << "Int8 copy constructor called " << src.toString() << std::endl;
}

//Still need to implement exception handling for overflow/underflow
Int8::Int8(const std::string numAsString, eOperandType type)
{
	int t = stold(numAsString);
	if (t > INT8_MAX)
	{
		std::cout << "Int8 overflow" << std::endl;
	}
	else if (t < INT8_MIN)
	{
		std::cout << "Int8 underflow" << std::endl;
	}
	else
	{
		int8_t temp = static_cast<int8_t>(t);
		this->_value = std::to_string(temp);
		this->_type = type;
	}
	// std::cout << "Constructor with of type: " << type << " value: " << numAsString << std::endl;
}

Int8::~Int8(void)
{
	std::cout << "Int8 destructor called" << std::endl;
}

int	Int8::getPrecision(void) const
{
	eOperandType precision = INT8;
	return precision;
}

eOperandType Int8::getType(void) const
{
	return this->_type;
}

std::string const & Int8::toString(void) const
{
	return this->_value;
}

IOperand const * Int8::operator+(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a + b));	
}

IOperand const * Int8::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a - b));	
}
IOperand const * Int8::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a * b));	
}

IOperand const * Int8::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a / b));	
}

IOperand const * Int8::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(std::fmod(a, b)));	
}

Int8 & Int8::operator=(Int8 const & src)
{
	std::cout << "Int8 copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
		this->_type = src.getType();
	}
	return *this;
}