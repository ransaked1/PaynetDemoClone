/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:26:52 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 02:26:55 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include <cstdlib>

class ScavTrap : public ClapTrap
{

public:

	ScavTrap(void);
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	std::string 	_name;
	void	challengeNewcomer(void);
};

#endif
