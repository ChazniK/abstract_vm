/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:20:37 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 15:09:56 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>


class Float: public IOperand
{
	public:

		Float(void);
		Float(const std::string numAsString, eOperandType type);
		Float(Float const & src);
		~Float(void);

		virtual int	getPrecision(void) const;
		virtual eOperandType getType(void) const;

		virtual IOperand const * operator+(IOperand const & rhs) const;
		virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;

		virtual std::string const & toString( void ) const;

		Float & operator=(Float const & src);

	private:

		std::string		_value;
		eOperandType	_type;
};

#endif
