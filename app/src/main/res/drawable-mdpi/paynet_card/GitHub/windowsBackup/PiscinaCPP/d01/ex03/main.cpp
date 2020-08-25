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
#include "ZombieHorde.hpp"

int		main()
{
	std::cout << "Program is starting" << std::endl;
	ZombieHorde		z(12);
	z.announce();
	std::cout << "Program ends" << std::endl;
	return (0);
}
