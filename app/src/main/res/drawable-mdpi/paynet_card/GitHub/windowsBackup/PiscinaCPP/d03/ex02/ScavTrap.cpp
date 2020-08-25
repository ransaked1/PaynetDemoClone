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

ScavTrap::ScavTrap() : ClapTrap("test")
{
	this->_Hp = 100;
	this->_Mhp = 100;
	this->_Ep = 50;
	this->_Mep = 50;
	this->_Lvl = 1;
	this->_Mad = 20;
	this->_Rad = 15;
	this->_Adr = 3;
	std::cout << "FR4G-TP" << " initialized!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name), _name(name)
{
	this->_Hp = 100;
	this->_Mhp = 100;
	this->_Ep = 50;
	this->_Mep = 50;
	this->_Lvl = 1;
	this->_Mad = 20;
	this->_Rad = 15;
	this->_Adr = 3;
	std::cout << "FR4G-TP " << this->_name << " is alive!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src._name)
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







