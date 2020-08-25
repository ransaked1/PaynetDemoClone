/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:35:02 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 00:35:03 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("test")
{
	this->_Hp = 100;
	this->_Mhp = 100;
	this->_Ep = 100;
	this->_Mep = 100;
	this->_Lvl = 1;
	this->_Mad = 30;
	this->_Rad = 20;
	this->_Adr = 5;
	std::cout << "FR4G-TP" << " initialized!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name), _name(name)
{
	this->_Hp = 100;
	this->_Mhp = 100;
	this->_Ep = 100;
	this->_Mep = 100;
	this->_Lvl = 1;
	this->_Mad = 30;
	this->_Rad = 20;
	this->_Adr = 5;
	std::cout << "FR4G-TP " << this->_name << " initialized!" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src._name)
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

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << this->_name << " deconstructed!" << std::endl;
	return ;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int 	i;
	const std::string names[]= {"falls on a fat troll", "jumping", "got hit", "crying too much",
		"tryed commiting suicide"};

	if ((this->_Ep - 25) >= 0)
	{
		i = rand() % 5;
		i = rand() % 5;
		i = rand() % 5;
		i = rand() % 5;
		i = rand() % 5;
		std::cout << "FR4G-TP " << this->_name << " " << names[i] << " on " << target <<
			std::endl;
		this->_Ep -= 25;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " is out of energy!" << std::endl;
}







