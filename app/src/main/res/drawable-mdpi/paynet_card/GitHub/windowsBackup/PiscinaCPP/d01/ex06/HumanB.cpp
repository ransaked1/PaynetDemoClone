/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:20:33 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 12:20:34 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->weapon1 = new Weapon("");
	this->_name = name;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon1 = &weapon;
	return ;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with his " << this->weapon1->_type << std::endl;
	return ;
}