/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:01:26 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 11:01:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main()
{
	std::string		brain = "HI THIS IS BRAIN";

	std::string		&brainref = brain;
	std::string		*brainpoint = &brain;

	std::cout << "Reference: " << brainref << " Pointer: " << *brainpoint << std::endl;
	return (0); 
}
