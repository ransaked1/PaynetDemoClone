/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:35:07 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 00:35:08 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap
{

public:

	FragTrap(void);
	FragTrap(std::string const name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap 	&operator=(FragTrap const &src);
	void	rangedAttack(std::string const &target);
	void 	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

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
