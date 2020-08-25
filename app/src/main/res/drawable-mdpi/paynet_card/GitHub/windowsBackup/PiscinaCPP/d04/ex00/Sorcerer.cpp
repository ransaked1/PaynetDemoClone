/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 05:30:57 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 05:31:00 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : _name("Robert"), _title("the Magnificent")
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return ;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
	this->_name = src._name;
	this->_title = src._title;
	return ;
}

Sorcerer	&Sorcerer::operator=(Sorcerer const &src)
{
	this->_name = src.getName();
	this->_title = src.getTitle();
	return (*this);
}

std::string		Sorcerer::getName() const
{
	return (this->_name);
}

std::string		Sorcerer::getTitle() const
{
	return (this->_title);
}

void			Sorcerer::polymorph(Victim const &src)
{
	src.getPolymorphed();
	return ;
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &src)
{
	o << "I am " << src.getName() << ", " << src.getTitle() << ", and I like ponies !" << std::endl;
	return (o);
}