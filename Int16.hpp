/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:18:47 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/09 16:18:57 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_HPP
#define INT16_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Int16: public IOperand
{
	public:

		Int16(void);
		Int16(const std::string numAsString, eOperandType type);
		Int16(Int16 const & src);
		~Int16(void);

		virtual int	getPrecision(void) const;
		virtual eOperandType getType(void) const;

		virtual IOperand const * operator+(IOperand const & rhs) const;
		virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;

		virtual std::string const & toString( void ) const;

		Int16 & operator=(Int16 const & src);

	private:

		std::string 	_value;
		eOperandType	_type;
};

#endif
