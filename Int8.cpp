/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:08:52 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/08 18:27:41 by ckatz            ###   ########.fr       */
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

Int8::Int8(const std::string numAsString, eOperandType type)
{
	this->_value = numAsString;
	this->_type = type;
	std::cout << "Constructor with type Int8 - value: " << numAsString <<" type: " << type << std::endl;
}

Int8::~Int8(void)
{
	std::cout << "Int8 destructor called" << std::endl;
}

int	Int8::getPrecision(void) const
{
	eOperandType precision = Int8;
	return precision;
}

eOperandType Int8::getType(void) const
{
	return ::INT8;
}

std::string const & Int8::toString(void) const
{
	return this->_value;
}

IOperand const * Int8::operator+(IOperand const & rhs) const
{
	eOperandType	newType;
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "adding\n";	
	long double result = a + b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return checkOperand(newType, result);	
}

IOperand const * Int8::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "subtracting\n";	
	long double result = a - b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return checkOperand(newType, result);
}
IOperand const * Int8::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "multiplying\n";	
	long double result = a * b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return checkOperand(newType, result);
}

IOperand const * Int8::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "dividing\n";	
	long double result = a / b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return checkOperand(newType, result);
}

IOperand const * Int8::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "modding\n";	
	long double result = std::fmod(a, b);
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return checkOperand(newType, result);

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
