/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:34 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/09 15:17:34 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FACTORY
#define OPERAND_FACTORY

#include "IOperand.hpp"

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

#include <cstdint>
#include <iostream>

class OperandFactory
{
	public:
		
		OperandFactory(void);
		~OperandFactory(void);
		IOperand const * createOperand(eOperandType type, std::string const & value) const;
		IOperand const * (OperandFactory::*funct[5])(std::string const & value) const;


	private:

		IOperand const * createInt8(std::string const & value) const;
		IOperand const * createInt16(std::string const & value) const;
		IOperand const * createInt32(std::string const & value) const;
		IOperand const * createFloat(std::string const & value) const;
		IOperand const * createDouble(std::string const & value) const;
};

#endif
