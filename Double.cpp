/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:21:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 15:01:33 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"
#include "Error.hpp"

Double::Double(void)
{

}

Double::Double(const std::string numAsString, eOperandType type)
{
	long double val = stold(numAsString);
	try
	{
		if (val > __DBL_MAX__)
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
		if (val < __DBL_MIN__)
		{
			throw Error::UnderflowException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	double_t temp = static_cast<double_t>(val);
	this->_value = std::to_string(temp);
	this->_type = type;
}

Double::~Double(void)
{

}

int	Double::getPrecision(void) const
{
	eOperandType precision = DOUBLE;
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
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a + b));
}

IOperand const * Double::operator-(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a - b));
}

IOperand const * Double::operator*(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a * b));
}

IOperand const * Double::operator/(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(a / b));
}

IOperand const * Double::operator%(IOperand const & rhs) const
{
	eOperandType	newType;
	OperandFactory	fact;
	
	long double a = std::stold(toString());
	long double b = std::stold(rhs.toString());
	newType =  (getPrecision() > rhs.getPrecision()) ? getType() : rhs.getType();
	return fact.createOperand(newType, std::to_string(std::fmod(a, b)));
}