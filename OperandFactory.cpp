/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:26 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 14:30:58 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"

OperandFactory::OperandFactory(void)
{
	this->funct[eOperandType::INT8] = &OperandFactory::createInt8;
	this->funct[eOperandType::INT16] = &OperandFactory::createInt16;
	this->funct[eOperandType::INT32] = &OperandFactory::createInt32;
	this->funct[eOperandType::FLOAT] = &OperandFactory::createFloat;
	this->funct[eOperandType::DOUBLE] = &OperandFactory::createDouble;
}

OperandFactory::~OperandFactory(void)
{

}

IOperand const * OperandFactory::createInt8(std::string const & value) const
{
	return new Int8(value, INT8);
}

IOperand const * OperandFactory::createInt16(std::string const & value) const
{
	return new Int16(value, INT16);
}

IOperand const * OperandFactory::createInt32(std::string const & value) const
{
	return new Int32(value, INT32);
}

IOperand const * OperandFactory::createFloat(std::string const & value) const
{
	return new Float(value, FLOAT);
}

IOperand const * OperandFactory::createDouble(std::string const & value) const
{
	return new Double(value, DOUBLE);
}

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{	
	return (this->*funct[type])(value);
}