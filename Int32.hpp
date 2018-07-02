/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:47:12 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/02 18:16:59 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
#define INT32_HPP

#include "IOperand.hpp"
#include <iostream>
#include <string>

class Int32: public IOperand
{
	public:

		Int32(void);
		Int32(Int32 const & src);
		Int32(const std::string numAsString);
		~Int32(void);
		
		virtual int	getPrecision(void) const;
		virtual eOperandType getType(void) const;

		int	getValue(void) const;
		operator int();
		//operator double();	
	
		virtual IOperand const * operator+(IOperand const & rhs) const;
		/*virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;*/		
	
		virtual std::string const & toString( void ) const;

		Int32 & operator=(Int32 const & src);

	private:

		int	_value;
};

#endif
