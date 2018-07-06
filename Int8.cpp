/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:08:52 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 12:24:09 by ckatz            ###   ########.fr       */
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

Int8::Int8(const std::string numAsString)
{
	this->_value = numAsString;
	std::cout << "Constructor with of type Int8 - value: " << numAsString << std::endl;
}

Int8::~Int8(void)
{
	std::cout << "Int8 destructor called" << std::endl;
}

int	Int8::getPrecision(void) const
{
	eOperandType precision = INT32;
	return precision;
}

eOperandType Int8::getType(void) const
{
	return ::INT8;
}

std::string const & Int8::toString( void ) const
{
	return this->_value;
}

IOperand const * Int8::operator+(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "adding\n";
	long double result = a + b;
	std::cout << "converting\n";
	return new Int8(std::to_string (static_cast<int8_t>(result)));
}

IOperand const * Int8::operator-(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "sub\n";
	long double result = a - b;
	std::cout << "converting\n";
	return new Int8(std::to_string (static_cast<int8_t>(result)));
}
IOperand const * Int8::operator*(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mul\n";
	long double result = a * b;
	std::cout << "converting\n";
	return new Int8(std::to_string (static_cast<int8_t>(result)));
}

IOperand const * Int8::operator/(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "div\n";
	long double result = a / b;
	std::cout << "converting\n";
	return new Int8(std::to_string (static_cast<int8_t>(result)));
}

IOperand const * Int8::operator%(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mod\n";
	long double result = std::fmod(a, b);
	std::cout << "converting\n";
	return new Int8(std::to_string (static_cast<int8_t>(result)));
}

Int8 & Int8::operator=(Int8 const & src)
{
	std::cout << "Int8 copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
	}
	return *this;
}
