/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:21:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/15 22:38:52 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"
#include "Error.hpp"

Float::Float(void)
{
	std::cout << "Float constructor called" << std::endl;
}

Float::Float(const std::string numAsString, eOperandType type)
{
	long double t = stold(numAsString);
	try
	{
		if (t > __FLT_MAX__)
		{
			throw Error::OverflowException();
		}
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	try 
	{
		if (t < __FLT_MIN__)
		{
			throw Error::UnderflowException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	float_t temp = static_cast<float_t>(t);
	this->_value = std::to_string(temp);
	this->_type = type;
	// std::cout << "Constructor with of type: " << type << " value: " << numAsString << std::endl;
}

Float::Float(Float const & src)
{
	std::cout << "Float copy constructor called " << src.toString() << std::endl;
}

Float::~Float(void)
{
	std::cout << "Float destructor called" << std::endl;
}

int	Float::getPrecision(void) const
{
	eOperandType precision = FLOAT;
	return precision;
}

eOperandType Float::getType(void) const
{
	return this->_type;
}

std::string const & Float::toString( void ) const
{
	return this->_value;
}

IOperand const * Float::operator+(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a + b));
}

IOperand const * Float::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a - b));
}
IOperand const * Float::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a * b));
}

IOperand const * Float::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a / b));
}

IOperand const * Float::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(std::fmod(a, b)));
}

Float & Float::operator=(Float const & src)
{
	std::cout << "Float copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.toString();
		this->_type = src.getType();
	}
	return *this;
}
