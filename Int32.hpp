/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:47:12 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/30 15:43:40 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
#define INT32_HPP

#include "IOperand.hpp"

class Int32: public IOperand
{
	public:
		
		int	getPrecision(void) const;
		eOperandType getType(void) const
	//	int	getValue(void) const;
		
		Int32 const * operator+(Int32 const & rhs) const;
		Int32 const * operator-(Int32 const & rhs) const;
		Int32 const * operator*(Int32 const & rhs) const;
		Int32 const * operator/(Int32 const & rhs) const;
		Int32 const * operator%(Int32 const & rhs) const;
		
		std::string const & toString( void ) const;

		Int32 & operator=(Int32 const & src);

		Int32(void);
		Int32(Int32 const & src);
		~Int32(void);

	private:

	//	int	_value;
};

#endif
