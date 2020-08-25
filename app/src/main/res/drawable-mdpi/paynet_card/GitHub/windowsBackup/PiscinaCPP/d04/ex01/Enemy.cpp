/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:18:23 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:18:25 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
	return ;
}

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
	return ;
}

Enemy	&Enemy::operator=(Enemy const &src)
{
	this->_hp = src._hp;
	this->_type = src._type;
	return (*this);
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
	this->_hp = src._hp;
	this->_type = src._type;
	this->_birth = src._birth;
	this->_death = src._death;
	return ;
}

Enemy::~Enemy()
{
	return ;
}

void 	Enemy::takeDamage(int dmg)
{
	(void) dmg;
	return ;
}


std::string		Enemy::getType() const
{
	return (this->_type);
}

int 			Enemy::getHP() const
{
	return (this->_hp);
}