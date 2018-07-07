/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:26 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/07 15:49:09 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"

// IOperand const * OperandFactory::createInt8( std::string const & value ) const
// {
	
// }

// IOperand const * OperandFactory::createInt16( std::string const & value ) const
// {

// }

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	IOperand	*result = NULL;
	long double	num;
	
	num = std::stold(value);
	if ( num < INT32_MIN)
	{
		std::cout << "Underflow error" << std::endl;
	}
	else if (num > INT32_MAX)
	{
		std::cout << "Overflow error" << std::endl;
	}
	else
	{
		result = new Int32(std::to_string (static_cast<int32_t>(num)), INT32);
	}
	return result;
}

// IOperand const * OperandFactory::createFloat( std::string const & value ) const
// {

// }

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
		result = new Int32(std::to_string (static_cast<int32_t>(num)), INT32);
	}
	return result;
}

// int do_it( int a, int b, int op ) {
//     typedef int (*fn)( int, int );

//     static fn funcs[] = { add, sub, mul, div };
    
//     assert( op < 4 && op >= 0 );
//     return funcs[ op ]( a, b );

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	typedef IOperand const *	(*funct)(std::string const & value);

	static funct fp[] = { &createInt32, &createDouble };

	return fp[type](value);
}

