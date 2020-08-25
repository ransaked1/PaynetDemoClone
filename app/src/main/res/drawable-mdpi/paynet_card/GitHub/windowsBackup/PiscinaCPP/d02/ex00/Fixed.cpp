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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void 	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
	return ;
}

Fixed 	&Fixed::operator=(Fixed const &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = fix.getRawBits();
	return *this;
}

const int	Fixed::literal = 8;