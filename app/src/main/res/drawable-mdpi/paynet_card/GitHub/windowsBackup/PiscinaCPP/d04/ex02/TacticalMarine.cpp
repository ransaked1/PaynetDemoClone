/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:59:04 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 10:59:10 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	i = 0;
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return ;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

ISpaceMarine* TacticalMarine::clone() const
{
	return ((ISpaceMarine*)this);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !" << std::endl;
	return ;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;
	return ;
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *" << std::endl;
	return ;
}

TacticalMarine &TacticalMarine::operator=(TacticalMarine const &src)
{
	this->i = src.i;
	return (*this);
}