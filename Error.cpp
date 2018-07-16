/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:31:27 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 14:18:11 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

const char* Error::UnknownInstructionException::what() const throw()
{
	return ("Error, unknown instruction entered");
}

const char* Error::ParserException::what() const throw()
{
	return ("Error, line can not be parsed");
}

const char* Error::InvalidOperandException::what() const throw()
{
	return ("Error, unknown operand entered");
}

const char* Error::OverflowException::what() const throw()
{
	return ("Error, overflow on value");
}

const char* Error::UnderflowException::what() const throw()
{
	return ("Error, underflow on value");
}

const char* Error::EmtyStackException::what() const throw()
{
	return ("Error, stack is empty");
}

const char* Error::DivisionModuloByZeroException::what() const throw()
{
	return ("Error, division or modulo by 0");
}

const char* Error::NoExitException::what() const throw()
{
	return ("Error, no exit found");
}

const char* Error::FalseAssertException::what() const throw()
{
	return ("Error, assert is not true");
}

const char* Error::TooFewValuesException::what() const throw()
{
	return ("Error, less than two values on stack");
}