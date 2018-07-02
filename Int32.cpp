/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/02 18:07:51 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32(void)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::Int32(Int32 const & src)
{
	std::cout << "Int32 copy constructor called " << src.getValue() << std::endl;
}

Int32::Int32(const std::string numAsString)
{
	this->_value = std::stoi(numAsString);
	std::cout << "Constructor with of type int32 - value: " << getValue() << std::endl;
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

int32_t Int32::getValue(void) const
{
	return this->_value;
}

Int32::operator int(void)
{
	return this->_value;
}

/*
Int32::operator double(void)
{
	return static_cast<double>(this->_value);
}
*/
IOperand const * Int32::operator+(IOperand const & rhs) const
{
	return Int32(getValue() + rhs.getValue());
}

/*IOperand const * Int32::operator-(IOperand const & rhs) const
{
	return Int32(getValue() - rhs.getValue());
}

IOperand const * Int32::operator*(IOperand const & rhs) const
{
	return IOperand(getValue() * rhs.getValue());
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	return IOperand(getValue() / rhs.getValue());
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	return IOperand(getValue() % rhs.getValue());
}*/

std::string const & Int32::toString( void ) const
{
	std::string numAsInt32 = "Hello";
	return numAsInt32;
}

Int32 & Int32::operator=(Int32 const & src)
{
	std::cout << "Int32 copy constructor called" << std::endl;
	if (this != &src)
	{
		this->_value = src.getValue();
	}
	return *this;
}
