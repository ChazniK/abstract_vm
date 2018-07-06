/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 12:02:18 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32(void)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::Int32(Int32 const & src)
{
	std::cout << "Int32 copy constructor called " << src.toString() << std::endl;
}

Int32::Int32(const std::string numAsString)
{
	this->_value = numAsString;
	std::cout << "Constructor with of type int32 - value: " << numAsString << std::endl;
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

std::string const & Int32::toString( void ) const
{
	return this->_value;
}

IOperand const * Int32::operator+(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "adding\n";	
	long double result = a + b;
	std::cout << "converting\n";
	return new Int32(std::to_string (static_cast<int32_t>(result)));
}

IOperand const * Int32::operator-(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "sub\n";	
	long double result = a - b;
	std::cout << "converting\n";
	return new Int32(std::to_string (static_cast<int32_t>(result)));
}
IOperand const * Int32::operator*(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mul\n";	
	long double result = a * b;
	std::cout << "converting\n";
	return new Int32(std::to_string (static_cast<int32_t>(result)));
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "div\n";	
	long double result = a / b;
	std::cout << "converting\n";
	return new Int32(std::to_string (static_cast<int32_t>(result)));
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mod\n";	
	long double result = std::fmod(a, b);
	std::cout << "converting\n";
	return new Int32(std::to_string (static_cast<int32_t>(result)));
}

Int32 & Int32::operator=(Int32 const & src)
{
	std::cout << "Int32 copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
	}
	return *this;
}
