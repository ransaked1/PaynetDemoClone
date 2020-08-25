/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:07:34 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 15:07:36 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

class ZombieEvent
{

public:

	void		setZombieType(std::string type); 
	Zombie 		*newZombie(std::string name);	
	Zombie 		*randomChump();

private:

	std::string	type;
};

#endif