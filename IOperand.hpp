/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:35:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/08 16:07:28 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>

enum	eOperandType { INT8, INT16, INT32, FLOAT, DOUBLE };
// enum	eOperand { int8_t, int16_t, int32_t, float_t, double_t };
 
class IOperand {

	public:

		virtual int	getPrecision(void) const = 0; // Precision of the type of the instance
		virtual eOperandType getType(void) const = 0; // Type of the instance
		
		virtual IOperand const * operator+(IOperand const & rhs) const = 0; // Sum
		virtual IOperand const * operator-(IOperand const & rhs) const = 0; // Difference
		virtual IOperand const * operator*(IOperand const & rhs) const = 0; // Product
		virtual IOperand const * operator/(IOperand const & rhs) const = 0; // Quotient
		virtual IOperand const * operator%(IOperand const & rhs) const = 0; // Modulo

		virtual std::string const & toString(void) const = 0; // String representation of the instance
		
		virtual ~IOperand(void) {}
};

#endif
