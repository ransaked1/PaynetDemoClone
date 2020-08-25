/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:15:36 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 11:15:38 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "The brain is created!" << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "The brain is destroyed!" << std::endl;
	return ;
}

std::string	Brain::identify(void)
{
	std::stringstream ss;
	ss << this;
	return ("Address of brain: " + ss.str());
}