/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:35:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 16:40:09 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>

enum	eOperandType { INT8, INT16, INT32, FLOAT, DOUBLE };
 
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
