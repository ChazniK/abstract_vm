/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:17:32 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 12:18:10 by ckatz            ###   ########.fr       */
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

Int16::Int16(const std::string numAsString)
{
	this->_value = numAsString;
	std::cout << "Constructor with of type int16 - value: " << numAsString << std::endl;
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
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "adding\n";
	long double result = a + b;
	std::cout << "converting\n";
	return new Int16(std::to_string (static_cast<int16_t>(result)));
}

IOperand const * Int16::operator-(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "sub\n";
	long double result = a - b;
	std::cout << "converting\n";
	return new Int16(std::to_string (static_cast<int16_t>(result)));
}
IOperand const * Int16::operator*(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mul\n";
	long double result = a * b;
	std::cout << "converting\n";
	return new Int16(std::to_string (static_cast<int16_t>(result)));
}

IOperand const * Int16::operator/(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "div\n";
	long double result = a / b;
	std::cout << "converting\n";
	return new Int16(std::to_string (static_cast<int16_t>(result)));
}

IOperand const * Int16::operator%(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mod\n";
	long double result = std::fmod(a, b);
	std::cout << "converting\n";
	return new Int16(std::to_string (static_cast<int16_t>(result)));
}

Int16 & Int16::operator=(Int16 const & src)
{
	std::cout << "Int16 copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
	}
	return *this;
}