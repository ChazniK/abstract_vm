/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:47:12 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/09 16:30:19 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
#define INT32_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Int32: public IOperand
{
	public:

		Int32(void);
		Int32(const std::string numAsString, eOperandType type);
		Int32(Int32 const & src);
		~Int32(void);

		virtual int	getPrecision(void) const;
		virtual eOperandType getType(void) const;

		virtual IOperand const * operator+(IOperand const & rhs) const;
		virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;		

		IOperand const * checkOperand(eOperandType newType, long double result) const;

		virtual std::string const & toString( void ) const;

		Int32 & operator=(Int32 const & src);

	private:
		std::string		_value;
		eOperandType	_type;
};

#endif
