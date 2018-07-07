/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:34 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/07 12:03:39 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FACTORY
#define OPERAND_FACTORY

#include "IOperand.hpp"
#include "Int32.hpp"
#include <cstdint>
#include <iostream>

class OperandFactory
{
	public:
		
		IOperand const * createOperand(eOperandType type, std::string const & value) const;
		// static void (*pf[])(void) = { createInt8, createInt16, createInt32, createFloat, createDouble };

	private:

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
};

#endif
