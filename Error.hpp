/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:00:06 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 14:11:32 by ckatz            ###   ########.fr       */
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
				virtual const char* what() const throw();
		};

		class ParserException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidOperandException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class OverflowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
				
		};

		class UnderflowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class EmtyStackException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionModuloByZeroException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoExitException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FalseAssertException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class TooFewValuesException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif