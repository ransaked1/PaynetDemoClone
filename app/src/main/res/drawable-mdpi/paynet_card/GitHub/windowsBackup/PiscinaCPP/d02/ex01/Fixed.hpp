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
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int 	toInt(void) const;

private:

	int					_fixed;
	static const int 	literal;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src); 

#endif
