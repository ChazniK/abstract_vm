/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:26 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/08 20:09:59 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"
#include <limits>

OperandFactory::OperandFactory(void)
{
	std::cout << "Double constructor called" << std::endl;
}

OperandFactory::~OperandFactory(void)
{
	std::cout << "Double destructor called" << std::endl;
}

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	IOperand	*result = NULL;
	long double	num;
	
	num = std::stold(value);
	if ( num < std::numeric_limits<int8_t>::min())
	{
		std::cout << "Underflow error" << std::endl;
	}
	else if ( num > std::numeric_limits<int8_t>::max())
	{
		std::cout << "Overflow error" << std::endl;
	}
	else
	{
		result = new Int8(std::to_string (static_cast<int8_t>(num)), INT8);
	}
	return result;
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	IOperand	*result = NULL;
	long double	num;
	
	num = std::stold(value);
	if ( num < std::numeric_limits<int16_t>::min())
	{
		std::cout << "Underflow error" << std::endl;
	}
	else if ( num > std::numeric_limits<int16_t>::max())
	{
		std::cout << "Overflow error" << std::endl;
	}
	else
	{
		result = new Int16(std::to_string (static_cast<int16_t>(num)), INT16);
	}
	return result;
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	IOperand	*result = NULL;
	long double	num;
	
	num = std::stold(value);
	if ( num < std::numeric_limits<int32_t>::min())
	{
		std::cout << "Underflow error" << std::endl;
	}
	else if ( num > std::numeric_limits<int32_t>::max())
	{
		std::cout << "Overflow error" << std::endl;
	}
	else
	{
		result = new Int32(std::to_string (static_cast<int32_t>(num)), INT32);
	}
	return result;
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	IOperand	*result = NULL;
	long double	num;
	
	num = std::stold(value);
	if ( num < std::numeric_limits<float>::min())
	{
		std::cout << "Underflow error" << std::endl;
	}
	else if ( num > std::numeric_limits<float>::max())
	{
		std::cout << "Overflow error" << std::endl;
	}
	else
	{
		result = new Float(std::to_string (static_cast<float_t>(num)), INT32);
	}
	return result;
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	IOperand	*result = NULL;
	long double	num;
	
	num = std::stold(value);
	if ( num < std::numeric_limits<double>::min())
	{
		std::cout << "Underflow error" << std::endl;
	}
	else if ( num > std::numeric_limits<double>::max())
	{
		std::cout << "Overflow error" << std::endl;
	}
	else
	{
		result = new Double(std::to_string (static_cast<double_t>(num)), INT32);
	}
	return result;
}

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	switch(type)
	{
		case 0:
			return createInt8(value);
			break;
		case 1:
			return createInt16(value);
			break;
		case 2:
			return createInt32(value);
			break;
		case 3:
			return createFloat(value);
			break;
		case 4:
			return createDouble(value);
			break;
		default:
			return NULL;
	}
}