/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:17:32 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/08 20:22:40 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int16.hpp"

Int16::Int16(void)
{
	std::cout << "Int16 constructor called" << std::endl;
}

Int16::Int16(Int16 const & src)
{
	std::cout << "Int16 copy constructor called " << src.toString() << std::endl;
}

Int16::Int16(const std::string numAsString, eOperandType type)
{
	this->_value = numAsString;
	std::cout << "Constructor of type int16 - value: " << numAsString << " type: " << type << std::endl;
}

Int16::~Int16(void)
{
	std::cout << "Int16 destructor called" << std::endl;
}

int	Int16::getPrecision(void) const
{
	eOperandType precision = INT32;
	return precision;
}

eOperandType Int16::getType(void) const
{
	return ::INT16;
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

	std::cout << "adding\n";	
	long double result = a + b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int16_t>(result)));	
}

IOperand const * Int16::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "subtracting\n";	
	long double result = a - b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int16_t>(result)));
}
IOperand const * Int16::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "multiplying\n";	
	long double result = a * b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int16_t>(result)));
}

IOperand const * Int16::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "dividing\n";	
	long double result = a / b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int16_t>(result)));
}

IOperand const * Int16::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "modding\n";	
	long double result = std::fmod(a, b);
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<int16_t>(result)));

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