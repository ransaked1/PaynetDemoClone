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
#include "ClapTrap.hpp"
#include <cstdlib>

class FragTrap : public ClapTrap
{

public:

	FragTrap(void);
	FragTrap(std::string const name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	std::string 	_name;
	void	vaulthunter_dot_exe(std::string const & target);

};

#endif
