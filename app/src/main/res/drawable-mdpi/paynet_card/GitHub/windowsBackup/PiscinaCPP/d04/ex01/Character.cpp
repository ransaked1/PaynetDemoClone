/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:20:36 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:20:38 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	return ;
}

Character::Character(std::string const &name) : _name(name)
{
	this->_ap = 40;
	this->w = NULL;
	return ;
}

Character::~Character()
{
	return ;
}

void		Character::recoverAP()
{
	if (this->_ap + 10 > 40)
		this->_ap = 40;
	else
		this->_ap += 10;
	return ;
}

void		Character::equip(AWeapon *wp)
{
	this->w = wp;
	return ;
}

void		Character::attack(Enemy *e)
{
	std::cout << this->_name << " attacks " << e->_type << " with a " << this->w->_name << std::endl;
	if (this->w->_ap > this->_ap)
		std::cout << "Not enough AP to shoot!" << std::endl;
	else
	{
		this->_ap -= this->w->_ap;
		this->w->attack();
		e->_hp -= this->w->_dmg;
		if (e->_hp <= 0)
			e->~Enemy();
	}
}

std::ostream	&operator<<(std::ostream &o, Character const &src)
{
	if (src.w != NULL)
		o << src._name << " has " << src._ap << " AP and wields a " << src.w->_name << std::endl;
	else
		o << src._name << " has " << src._ap << " AP and is unarmed" << std::endl;
	return (o);
}


