/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:20:57 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 14:20:59 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{

public:

	Pony(std::string ponyColor);
	~Pony(void);

	std::string		getPonyColor(void);

	std::string		_ponyColor;
};

#endif