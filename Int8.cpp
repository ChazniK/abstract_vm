/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:08:52 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/17 10:34:05 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"
#include "Error.hpp"

Int8::Int8(void)
{
	
}

Int8::Int8(const std::string numAsString, eOperandType type)
{
	int t = stold(numAsString);
	try
	{
		if (t > INT8_MAX)
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
		if (t < INT8_MIN)
		{
			throw Error::UnderflowException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	int8_t temp = static_cast<int8_t>(t);
	this->_value = std::to_string(temp);
	this->_type = type;
}

Int8::~Int8(void)
{

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