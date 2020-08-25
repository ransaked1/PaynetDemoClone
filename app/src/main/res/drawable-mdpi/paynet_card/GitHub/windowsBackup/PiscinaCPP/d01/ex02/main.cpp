/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:07:41 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 15:07:42 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main()
{
	std::cout << "Program is starting" << std::endl;
	ZombieEvent *z1 = new ZombieEvent();
	ZombieEvent *z2 = new ZombieEvent();

	z1->setZombieType("NoHead");
	Zombie *another = z1->newZombie("Andrew");
	z1->randomChump();
	z2->setZombieType("NoLegs");
	Zombie *another2 = z2->newZombie("Jack");
	another2->announce();
	delete another;
	delete another2;
	std::cout << "Program ends" << std::endl;
	return (0);
}
