/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:18:15 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:18:16 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("PowerFist", 8, 50)
{
	this->_outAttack = "* pschhh... SBAM! *";
	return ;
}

PowerFist::~PowerFist()
{
	return ;
}

void		PowerFist::attack() const
{
	std::cout << this->_outAttack << std::endl;
	return ;
}