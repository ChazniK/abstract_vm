/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:34 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 17:41:43 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FACTORY
#define OPERAND_FACTORY

#include "IOperand.hpp"

class OperandFactory
{
	public:
		
		IOperand const * createOperand(eOperandType type, std::string const & value) const;
		static void (*pf[])(void) = { createInt8, createInt16, createInt32, createFloat, createDouble };

	private:

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;i
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
}

#endif
