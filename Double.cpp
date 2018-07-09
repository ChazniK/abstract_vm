/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:21:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/08 21:08:57 by ckatz            ###   ########.fr       */
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

Double::Double(const std::string numAsString, eOperandType type)
{
	this->_value = numAsString;
	this->_type = type;
	std::cout << "Constructor with type Double - value: " << numAsString << "type: " << type << std::endl;
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
	return this->_type;
}

std::string const & Double::toString( void ) const
{
	return this->_value;
}

IOperand const * Double::operator+(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "adding\n";	
	long double result = a + b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<double_t>(result)));	
}

IOperand const * Double::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "subtracting\n";	
	long double result = a - b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<double_t>(result)));
}
IOperand const * Double::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "multiplying\n";	
	long double result = a * b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<double_t>(result)));
}

IOperand const * Double::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "dividing\n";	
	long double result = a / b;
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<double_t>(result)));
}

IOperand const * Double::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;

	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());

	std::cout << "modding\n";	
	long double result = std::fmod(a, b);
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(static_cast<double_t>(result)));
}

Double & Double::operator=(Double const & src)
{
	std::cout << "Double copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
		this->_type = src.getType();
	}
	return *this;
}
