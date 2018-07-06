/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:21:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 12:21:05 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

Float::Float(void)
{
	std::cout << "Float constructor called" << std::endl;
}

Float::Float(Float const & src)
{
	std::cout << "Float copy constructor called " << src.toString() << std::endl;
}

Float::Float(const std::string numAsString)
{
	this->_value = numAsString;
	std::cout << "Constructor with of type float - value: " << numAsString << std::endl;
}

Float::~Float(void)
{
	std::cout << "Float destructor called" << std::endl;
}

int	Float::getPrecision(void) const
{
	eOperandType precision = INT32;
	return precision;
}

eOperandType Float::getType(void) const
{
	return ::FLOAT;
}

std::string const & Float::toString( void ) const
{
	return this->_value;
}

IOperand const * Float::operator+(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "adding\n";
	long double result = a + b;
	std::cout << "converting\n";
	return new Float(std::to_string (static_cast<float_t>(result)));
}

IOperand const * Float::operator-(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "sub\n";
	long double result = a - b;
	std::cout << "converting\n";
	return new Float(std::to_string (static_cast<float_t>(result)));
}
IOperand const * Float::operator*(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mul\n";
	long double result = a * b;
	std::cout << "converting\n";
	return new Float(std::to_string (static_cast<float_t>(result)));
}

IOperand const * Float::operator/(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "div\n";
	long double result = a / b;
	std::cout << "converting\n";
	return new Float(std::to_string (static_cast<float_t>(result)));
}

IOperand const * Float::operator%(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mod\n";
	long double result = std::fmod(a, b);
	std::cout << "converting\n";
	return new Float(std::to_string (static_cast<float_t>(result)));
}

Float & Float::operator=(Float const & src)
{
	std::cout << "Float copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
	}
	return *this;
}
