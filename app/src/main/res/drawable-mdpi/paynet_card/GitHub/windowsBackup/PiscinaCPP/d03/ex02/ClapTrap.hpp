/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:43:09 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 02:43:10 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

public:

	ClapTrap(void);
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	ClapTrap 	&operator=(ClapTrap const &src);
	void	rangedAttack(std::string const &target);
	void 	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

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
