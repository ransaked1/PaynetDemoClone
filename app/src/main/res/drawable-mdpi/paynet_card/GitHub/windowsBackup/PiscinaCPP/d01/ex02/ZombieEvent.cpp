/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:07:28 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 15:07:30 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <cstdlib>
#include <ctime>

void		ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie 		*ZombieEvent::newZombie(std::string name)
{
	Zombie *zomb = new Zombie();

	zomb->Zombie::setType(this->type);
	zomb->Zombie::setName(name);
	return (zomb);
}

Zombie 		*ZombieEvent::randomChump()
{
	Zombie *zomb = new Zombie();
	int		n;
	std::string options[10] = {"Jake", "Andrew", "Steve", "Anders", "Jim", "Bob", "Kelvin", "Ali", "Sam", "Kily"};

	srand(time(NULL));
	n = rand() % 10;
	n = rand() % 10;
	n = rand() % 10;
	n = rand() % 10;
	n = rand() % 10;
	n = rand() % 10;
	n = rand() % 10;
	zomb->Zombie::setType(this->type);
	zomb->Zombie::setName(options[rand() % 10]);
	zomb->Zombie::announce();

	return(zomb);
}