/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:20:43 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 14:20:45 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string ponyColor) : _ponyColor(ponyColor)
{
	std::cout << "The " << _ponyColor << " pony is created" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << "The " << _ponyColor << " pony is destroyed" << std::endl;
	return ;
}

std::string		Pony::getPonyColor()
{
	return this->_ponyColor;
}
