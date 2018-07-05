/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:47:12 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/05 18:50:01 by ckatz            ###   ########.fr       */
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
		Int32(double num);
		~Int32(void);
		
		int				getPrecision(void) const;
		eOperandType	getType(void) const;
		double			getValue() const;
		void			setValue(double val);
		IOperand const *operator+(IOperand const & rhs) const;
		/*virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;*/		
	
		std::string const & toString( void ) const;

		Int32 & operator=(Int32 const & src);
	
private:
	   double	_value;
};

#endif
