/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:14:14 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/07 18:14:17 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string.h>
#include <ostream>

class Fixed
{
	private:
			int _fixedPointValue;
			static const int _fractionalBit = 8;

	public:

			//>, <, >=, <=, == and !=
			Fixed(void);
			~Fixed(void);
			Fixed(Fixed const & src);
			Fixed & operator=(Fixed const & src); 
			Fixed (const int n);
			Fixed (const float n);


			float toFloat( void ) const;
			int toInt( void ) const;
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			int getInt(void)const;

			bool operator<(Fixed const & src) const;
			bool operator>(Fixed const & src) const;
			bool operator>=(Fixed const & src) const;
			bool operator<=(Fixed const & src) const;
			bool operator==(Fixed const & src) const;
			bool operator!=(Fixed const & src) const;

			Fixed operator+(Fixed const & src) const;
			Fixed operator-(Fixed const & src) const;
			Fixed operator*(Fixed const & src) const;
			Fixed operator/(Fixed const & src) const;
			
			Fixed operator++( void );
			Fixed operator++( int );

			static Fixed min(Fixed lhs, Fixed rhs);
			static Fixed max(Fixed lhs, Fixed rhs);
};
std::ostream &		operator<<(std::ostream & o, Fixed const & rhs);

#endif