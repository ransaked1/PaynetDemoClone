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

FragTrap::FragTrap() : _Hp(100), _Mhp(100), _Ep(100), _Mep(100), _Lvl(1), _Mad(30), _Rad(20), _Adr(5)
{
	std::cout << "FR4G-TP" << " initialized!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const name) : _Hp(100), _Mhp(100), _Ep(100), _Mep(100), _Lvl(1), _Mad(30), _Rad(20),
	_Adr(5), _name(name)
{
	std::cout << "FR4G-TP " << this->_name << " initialized!" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src)
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

FragTrap 	&FragTrap::operator=(FragTrap const &src)
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

void	FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << 
		this->_Rad << " points of danage!" << std::endl;
	return ;
}

void	FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << 
		this->_Mad << " points of danage!" << std::endl;
	return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if ((int)(this->_Hp - (amount - this->_Adr)) < 0)
		this->_Hp = 0;
	else
		this->_Hp -= (amount - this->_Adr);
	std::cout << "FR4G-TP " << this->_name << " took " << amount << " points of damage. " <<
		this->_Hp << " points remaining!" << std::endl;
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if ((this->_Hp + amount) > 100)
		this->_Hp = 100;
	else
		this->_Hp += amount;
	std::cout << "FR4G-TP " << this->_name << " was repaired for " << amount <<
	" points of health. Now got " << this->_Hp << " points of health!" << std::endl;
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







