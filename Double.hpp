/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:20:37 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/09 16:45:38 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"

#include <iostream>
#include <string>
#include <cmath>

class Double: public IOperand
{
	public:

		Double(void);
		Double(const std::string numAsString, eOperandType type);
		Double(Double const & src);
		~Double(void);

		virtual int	getPrecision(void) const;
		virtual eOperandType getType(void) const;

		virtual IOperand const * operator+(IOperand const & rhs) const;
		virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;

		virtual std::string const & toString( void ) const;

		Double & operator=(Double const & src);

	private:

		std::string		_value;
		eOperandType	_type;
};

#endif
