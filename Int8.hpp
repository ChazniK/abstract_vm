/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:17:59 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/17 10:33:53 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
#define INT8_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"

#include <iostream>
#include <string>
#include <cmath>

class Int8: public IOperand
{
	public:

		Int8(void);
		Int8(const std::string numAsString, eOperandType type);
		Int8(Int8 const & src);	
		~Int8(void);

		virtual int	getPrecision(void) const;
		virtual eOperandType getType(void) const;

		virtual IOperand const * operator+(IOperand const & rhs) const;
		virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;

		virtual std::string const & toString( void ) const;

		Int8 & operator=(Int8 const & src);

	private:

		std::string		_value;
		eOperandType	_type;
};

#endif
