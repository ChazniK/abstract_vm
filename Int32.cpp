/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/05 18:50:03 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32(void)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::Int32(Int32 const & src)
{
	std::cout << "Int32 copy constructor called " << std::endl;
}

Int32::Int32(double num)
{
	this->_value = std::stod(num);
	std::cout << "Constructor with of type int32 - value: " << std::endl;
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

double	Int32::getValue(void) const
{
	return this->_value;
}

void Int32::setValue(double value)
{
	this->_value = value;
}
/*
Int32::operator int(void)
{
	return this->_value;
}

Int32::operator double(void)
{
	return static_cast<double>(this->_value);
}
*/
IOperand const * Int32::operator+(IOperand const & rhs) const
{

	Int32 * val1 = dynamic_cast<Int32*>(getValue());
	Int32 & val2 = dynamic_cast<Int32>(rhs.getValue());
	return new (Int32(val1->getValue() + val2.getValue()));


	//Int32 *newRhs = &rhs;
	//Int32 const * rhs = reinterpret_cast <Int32 const *>(*newRhs);
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
}
*/

std::string const & Int32::toString( void ) const
{
	return *(new std::string("NULL"));
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
