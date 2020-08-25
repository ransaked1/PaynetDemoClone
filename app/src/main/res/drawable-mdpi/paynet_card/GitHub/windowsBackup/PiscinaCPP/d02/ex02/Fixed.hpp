/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:43:15 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 19:43:16 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

public:

	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	Fixed 	&operator=(Fixed const &fix);
	Fixed 	operator-(Fixed const &fix) const;
	Fixed 	operator+(Fixed const &fix) const;
	Fixed 	operator*(Fixed const &fix) const;
	Fixed 	operator/(Fixed const &fix) const;
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int 	toInt(void) const;
	bool	operator<(Fixed const &fix);
	bool	operator>(Fixed const &fix);
	bool	operator>=(Fixed const &fix);
	bool	operator<=(Fixed const &fix);
	bool	operator==(Fixed const &fix);
	bool	operator!=(Fixed const &fix);
	Fixed 	&operator++();
	Fixed 	operator++(int src);

	static Fixed 		&min(Fixed &f1, Fixed &f2);
	static Fixed const	&min(Fixed const &f1, Fixed const &f2);
	static Fixed 		&max(Fixed &f1, Fixed &f2);
	static Fixed const	&max(Fixed const &f1, Fixed const &f2);

private:

	int					_fixed;
	static const int 	literal;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src); 

#endif
