/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:15:58 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 11:16:00 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	std::cout << "The human is created!" << std::endl;
	this->brain = new Brain();
	return ;
}

Human::~Human(void)
{
	std::cout << "The human is destroyed!" << std::endl;
	brain->~Brain();
	return ;
}

std::string 	Human::identify(void)
{
	return (brain->identify());
}

Brain 	&Human::getBrain(void)
{
	return (*brain);
}
