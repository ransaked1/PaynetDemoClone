/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:19:57 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 19:19:59 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	int		i;
	int		k;

	i = 0;
	k = rand() % 10;
	k = rand() % 10;
	k = rand() % 10;
	k = rand() % 10;
	k = rand() % 10;
	k = rand() % 10;
	k = rand() % 10;
	this->zombieHorde = new Zombie[n];
	this->N = n;
	std::string options[10] = {"Jake", "Andrew", "Steve", "Anders", "Jim", "Bob", "Kelvin", "Ali", "Sam", "Kily"};
	while (i < n)
	{
		zombieHorde[i].setName(options[rand() % 10]);
		i++;
	}
}

ZombieHorde::~ZombieHorde(void)
{
	std::cout << "ZombieHorde is getting destroyed" << std::endl;
	delete [] this->zombieHorde;
	return ;
}

void	ZombieHorde::announce(void)
{
	int		i;

	i = 0;
	while (i < this->N)
	{
		this->zombieHorde[i].announce();
		i++;
	}
}
