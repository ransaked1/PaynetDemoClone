/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:43:03 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 02:43:05 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "CL4P-TP " << _name << " came into existence" << std::endl;
	return ;
}

ClapTrap::ClapTrap(void)
{
	std::cout << "CL4P-TP " << " came into existence" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CL4P-TP " << this->_name << " went to valhala" << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	(void)rhs;
	return *this;
}

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name <<  " pokes " <<  target << " at range , dealing " << this->_Rad << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name <<  " pokes " <<  target << " at melee , dealing " << this->_Mad << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->_Hp - ((int)amount - this->_Adr)) < 0)
		this->_Hp = 0;
	else
		this->_Hp -= ((int)amount - this->_Adr);

	std::cout << this->_name <<  " took " << amount - this->_Adr << " points of damage like a man" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->_Hp + (int)amount) > this->_Mhp)
		this->_Hp = this->_Mhp;
	else
		this->_Hp += (int)amount;

	std::cout << this->_name <<  " used green magic to heal himself for  " << amount << " hit points!" << std::endl;

}
