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

class ScavTrap
{

public:

	ScavTrap(void);
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	ScavTrap 	&operator=(ScavTrap const &src);
	void	rangedAttack(std::string const &target);
	void 	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(void);

	int 	_Hp;
	int 	_Mhp;
	int 	_Ep;
	int 	_Mep;
	int 	_Lvl;
	std::string 	_name;
	int 	_Mad;
	int 	_Rad;
	int 	_Adr;
};

#endif
