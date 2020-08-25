/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:17:27 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:17:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
	return ;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _dmg(damage), _ap(apcost)
{
	return ;
}

AWeapon::AWeapon(AWeapon const &src)
{
	*this = src;
	this->_name = src._name;
	this->_outAttack = src._outAttack;
	this->_dmg = src._dmg;
	this->_ap = src._ap;
	return ;
}

AWeapon::~AWeapon()
{
	return ;
}

std::string		AWeapon::getName() const
{
	return (this->_name);
}

int				AWeapon::getAPCost() const
{
	return (this->_ap);
}

int				AWeapon::getDamage() const
{
	return (this->_dmg);
}