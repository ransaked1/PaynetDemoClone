/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:19:58 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 12:19:59 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{

public:

	Weapon(std::string type);
	~Weapon(void);

	const std::string	&getType();
	void				setType(std::string type);
	std::string		_type;
};

#endif
