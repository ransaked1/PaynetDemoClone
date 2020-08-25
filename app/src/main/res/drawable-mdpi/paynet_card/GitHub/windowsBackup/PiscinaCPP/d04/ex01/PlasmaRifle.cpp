/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:17:43 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:17:45 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("PlasmaRifle", 5, 21)
{
	this->_outAttack = "* piouuu piouuu piouuu *";
	return ;
}

PlasmaRifle::~PlasmaRifle()
{
	return ;
}

void		PlasmaRifle::attack() const
{
	std::cout << this->_outAttack << std::endl;
	return ;
}
