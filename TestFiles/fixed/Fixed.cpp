/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:14:03 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/30 15:43:10 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed Fixed::min(Fixed lhs, Fixed rhs)
{
	return ((lhs < rhs)? lhs : rhs );
}

Fixed Fixed::max(Fixed lhs, Fixed rhs)
{
	return ((lhs > rhs)? lhs : rhs );
}

Fixed Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed fix;
	fix = *this;
		this->_fixedPointValue++;
return (fix);
}

Fixed Fixed::operator*(Fixed const & src) const
{
	return Fixed(toFloat() * src.toFloat());
}

Fixed Fixed::operator+(Fixed const & src) const
{
	return Fixed(toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed const & src) const
{
	return Fixed(toFloat() - src.toFloat());
}
Fixed Fixed::operator/(Fixed const & src) const
{
	return Fixed(toFloat() / src.toFloat());
}

bool Fixed::operator<(Fixed const & src) const
{
	if (this->_fixedPointValue < src._fixedPointValue)
		return true;
	return false;
}

bool Fixed::operator>(Fixed const & src) const
{
	if (this->_fixedPointValue > src._fixedPointValue)
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const & src) const
{
	if (this->_fixedPointValue <= src._fixedPointValue)
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const & src) const
{
	if (this->_fixedPointValue >= src._fixedPointValue)
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const & src) const
{
	if (this->_fixedPointValue != src._fixedPointValue)
		return true;
	return false;
}

bool Fixed::operator==(Fixed const & src) const
{
	if (this->_fixedPointValue == src._fixedPointValue)
		return true;
	return false;
}



Fixed::Fixed (const int n)
{
	 int temp;
	 temp = n << this->_fractionalBit;
	 this->_fixedPointValue = temp;
	//  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float n)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(((n) * (1 << this->_fractionalBit)));
}


int Fixed::toInt( void ) const
{
	int temp;

	temp = this->_fixedPointValue >>this->_fractionalBit;
	return temp;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPointValue) / (1 << this->_fractionalBit);
	
}

Fixed::Fixed ( void )
{
	this->_fixedPointValue = 0;
	// std::cout<<"Default constructor called"<<std::endl;
	return ;
}

Fixed::~Fixed( void )
{
	// std::cout<<"Destructor called"<<std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	// std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
	return ;
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

Fixed &		Fixed::operator=(Fixed const & src)
{
	// std::cout<<"Assignation operator called"<<std::endl;
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();

	return *this;	
}

int Fixed::getInt(void)const
{
	return this->_fixedPointValue;
}

std::ostream & operator << (std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
