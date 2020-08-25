/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:21:05 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 14:21:07 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony 	*pinkPony = new Pony("pink");

	std::cout << "Hey, this is a " << pinkPony->getPonyColor() << " pony" << std::endl;

	delete pinkPony;

	std::cout << "The pink pony function ends" << std::endl << std::endl;
}

void	ponyOnTheStak(void)
{
	Pony 	redPony("red");

	std::cout << "Hey, this is a " << redPony.getPonyColor() << " pony" << std::endl;

	std::cout << "The red pony function ends" << std::endl;
}

int		main()
{
	std::cout << "The program starts" << std::endl << std::endl;

	ponyOnTheHeap();

	ponyOnTheStak();

	std::cout << std::endl <<  "The program ends" << std::endl;
}
