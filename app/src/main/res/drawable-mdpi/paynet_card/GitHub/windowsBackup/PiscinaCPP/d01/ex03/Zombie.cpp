/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:07:08 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 15:07:09 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout <<  "<" << this->_name << " (" << this->_type << ")> " << "Aaarrrrh" << std::endl;
	return ;
}

void	Zombie::setType(std::string type)
{
	this->_type = type;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void 	Zombie::announce()
{
	std::cout <<  "<" << this->_name << " (" << this->_type << ")> " << "Brrrrraaaiiinssssss" << std::endl;
	return ;
}