/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:21:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 16:01:29 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

Double::Double(void)
{
	std::cout << "Double constructor called" << std::endl;
}

Double::Double(Double const & src)
{
	std::cout << "Double copy constructor called " << src.toString() << std::endl;
}

Double::Double(const std::string numAsString)
{
	this->_value = numAsString;
	std::cout << "Constructor with of type Double - value: " << numAsString << std::endl;
}

Double::~Double(void)
{
	std::cout << "Double destructor called" << std::endl;
}

int	Double::getPrecision(void) const
{
	eOperandType precision = INT32;
	return precision;
}

eOperandType Double::getType(void) const
{
	return ::DOUBLE;
}

std::string const & Double::toString( void ) const
{
	return this->_value;
}

IOperand const * Double::operator+(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "adding\n";
	long double result = a + b;
	std::cout << "converting\n";
	return new Double(std::to_string (static_cast<double_t>(result)));
}

IOperand const * Double::operator-(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "sub\n";
	long double result = a - b;
	std::cout << "converting\n";
	return new Double(std::to_string (static_cast<double_t>(result)));
}
IOperand const * Double::operator*(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mul\n";
	long double result = a * b;
	std::cout << "converting\n";
	return new Double(std::to_string (static_cast<double_t>(result)));
}

IOperand const * Double::operator/(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "div\n";
	long double result = a / b;
	std::cout << "converting\n";
	return new Double(std::to_string (static_cast<double_t>(result)));
}

IOperand const * Double::operator%(IOperand const & rhs) const
{
	long double a = std::stold(this->_value);
	long double b = std::stold(rhs.toString());
	std::cout << "mod\n";
	long double result = std::fmod(a, b);
	std::cout << "converting\n";
	return new Double(std::to_string (static_cast<double_t>(result)));
}

Double & Double::operator=(Double const & src)
{
	std::cout << "Double copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
	}
	return *this;
}
