/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:00:06 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/15 13:23:23 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>

class Error
{
	public:

		class UnknownInstructionException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, unknown instruction entered");
				}
		};
		
		class OverflowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, overflow on value");
				}
		};

		class UnderlowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, underflow on value");
				}
		};

		class PopOnEmtyStackException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, pop on empty stack");
				}
		};

		class DivisionModuloByZeroException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, division or modulo by 0");
				}
		};

		class NoExitException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, no exit found");
				}
		};

		class FalseAssertException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, assert is not true");
				}
		};

		class TooFewValuesException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error, less than two values on stack");
				}
		};
};

#endif