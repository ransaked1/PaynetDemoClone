/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:43:21 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 19:43:23 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = n * 256;
	return ;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(n * 256);
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

int		Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void 	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
	return ;
}

Fixed 	&Fixed::operator=(Fixed const &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = fix.getRawBits();
	return *this;
}

float 	Fixed::toFloat(void) const
{
	return (this->_fixed / 256.0);
}

int 	Fixed::toInt(void) const
{
	return (this->_fixed / 256);
}

Fixed 	Fixed::operator-(Fixed const &fix) const
{
	Fixed rez;
	rez._fixed = this->_fixed - fix.getRawBits();
	return (rez);
}

Fixed 	Fixed::operator+(Fixed const &fix) const
{
	Fixed rez;
	rez._fixed = this->_fixed + fix.getRawBits();
	return (rez);
}

Fixed 	Fixed::operator*(Fixed const &fix) const
{
	Fixed rez;
	rez._fixed = (this->_fixed * fix.getRawBits()) / 256;
	return (rez);
}

Fixed 	Fixed::operator/(Fixed const &fix) const
{
	Fixed rez;
	rez._fixed = this->_fixed / fix.getRawBits();
	return (rez);
}

bool	Fixed::operator<(Fixed const &fix)
{
	if (this->_fixed < fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(Fixed const &fix)
{
	if (this->_fixed > fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &fix)
{
	if (this->_fixed >= fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &fix)
{
	if (this->_fixed <= fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &fix)
{
	if (this->_fixed < fix.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &fix)
{
	if (this->_fixed < fix.getRawBits())
		return (true);
	return (false);
}

Fixed 	&Fixed::operator++()
{
	this->_fixed += 1;
	return (*this);
}

Fixed 	Fixed::operator++(int src)
{
	(void)src;
	Fixed rez(*this);
	++(*this);
	return rez;
}

Fixed 	&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1._fixed > f2._fixed ? f2 : f1);
}

Fixed const	&Fixed::min(Fixed const &f1, Fixed const &f2)
{
	return (f1._fixed > f2._fixed ? f2 : f1);
}

Fixed 	&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1._fixed > f2._fixed ? f1 : f2);
}

Fixed const	&Fixed::max(Fixed const &f1, Fixed const &f2)
{
	return (f1._fixed > f2._fixed ? f1 : f2);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &src)
{
	o << src.getRawBits() / 256.0;
	return (o);
}

const int	Fixed::literal = 8;








