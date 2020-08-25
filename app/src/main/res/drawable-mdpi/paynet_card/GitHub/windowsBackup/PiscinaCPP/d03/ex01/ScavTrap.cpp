/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:26:35 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 02:26:38 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _Hp(100), _Mhp(100), _Ep(50), _Mep(50), _Lvl(1), _Mad(20), _Rad(15), _Adr(3)
{
	std::cout << "FR4G-TP" << " initialized!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const name) : _Hp(100), _Mhp(100), _Ep(50), _Mep(50), _Lvl(1), _Mad(20), _Rad(15),
	_Adr(3), _name(name)
{
	std::cout << "FR4G-TP " << this->_name << " is alive!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
	this->_Hp = src._Hp;
	this->_Mhp = src._Mhp;
	this->_Ep = src._Ep;
	this->_Mep = src._Mep;
	this->_Lvl = src._Lvl;
	this->_Mad = src._Mad;
	this->_Rad = src._Rad;
	this->_Adr = src._Adr;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "FR4G-TP " << this->_name << " destroyed foe EVER!" << std::endl;
	return ;
}

ScavTrap 	&ScavTrap::operator=(ScavTrap const &src)
{
	this->_Hp = src._Hp;
	this->_Mhp = src._Mhp;
	this->_Ep = src._Ep;
	this->_Mep = src._Mep;
	this->_Lvl = src._Lvl;
	this->_Mad = src._Mad;
	this->_Rad = src._Rad;
	this->_Adr = src._Adr;
	return (*this);
}

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at distance, causing " << 
		this->_Rad << " HP loss!" << std::endl;
	return ;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << 
		this->_Mad << " blood to drop!" << std::endl;
	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if ((int)(this->_Hp - (amount - this->_Adr)) < 0)
		this->_Hp = 0;
	else
		this->_Hp -= (amount - this->_Adr);
	std::cout << "FR4G-TP " << this->_name << " took " << amount << " points of damage. " <<
		this->_Hp << " points remaining!" << std::endl;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if ((this->_Hp + amount) > 100)
		this->_Hp = 100;
	else
		this->_Hp += amount;
	std::cout << "FR4G-TP " << this->_name << " was repaired for " << amount <<
	" points of health. Now got " << this->_Hp << " points of health!" << std::endl;
	return ;
}

void	ScavTrap::challengeNewcomer(void)
{
	int 	i;
	const std::string names[]= {"jumping in one leg", "squirl", "laugh and cry", "dig a 100m hole",
		"say a bad joke 100times"};

	if ((this->_Ep - 25) >= 0)
	{
		i = rand() % 5;
		i = rand() % 5;
		i = rand() % 5;
		i = rand() % 5;
		i = rand() % 5;
		std::cout << "FR4G-TP " << this->_name << " " << names[i] << std::endl;
		this->_Ep -= 25;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " is out of energy!" << std::endl;
}







