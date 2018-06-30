/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:19 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/30 15:43:43 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32(void)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::Int32(Fixed const & src)
{
	std::cout << "Int32 constructor called" << std::endl;
}

Int32::~Int32(void)
{
	std::cout << "Int32 destructor called" << std::endl;
}

int	Int32::getPrecision(void) const
{	
	eOperandType precision = Int32;
	return precision;
	//return eOperandType::Int32;
}

eOperandType Int32::getType(void) const
{
	return ::Int32;
}

/*int	getValue(void) const
{

}*/

Int32 const * Int32::operator+(IOperand const & rhs) const
{
	return 
}
    
Int32 const * Int32::operator-(IOperand const & rhs) const
{

}
    
Int32 const * Int32::operator*(IOperand const & rhs) const
{

}

Int32 const * Int32::operator/(IOperand const & rhs) const
{

}

Int32 const * Int32::operator%(IOperand const & rhs) const
{

}

std::string const & Int32::toString( void ) const
{

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



