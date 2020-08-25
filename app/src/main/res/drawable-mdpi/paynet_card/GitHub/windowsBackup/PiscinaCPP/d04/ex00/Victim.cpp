/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 05:31:33 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 05:31:34 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim() : _name("Jimmy")
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return ;
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return ;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
	return ;
}

Victim::Victim(Victim const &src)
{
	*this = src;
	this->_name = src._name;
	return ;
}

Victim 		&Victim::operator=(Victim const &src)
{
	this->_name = src.getName();
	return (*this);
}

std::string		Victim::getName() const
{
	return (this->_name);
}

void			Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Victim const &src)
{
	o << "I'm " << src.getName() << " and I like otters !" << std::endl;
	return (o);
}