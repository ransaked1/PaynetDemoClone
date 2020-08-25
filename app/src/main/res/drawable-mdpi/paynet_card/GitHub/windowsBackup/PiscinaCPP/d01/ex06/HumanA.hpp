/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:20:24 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/25 12:20:26 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void);

private:

	std::string		_name;
	Weapon 			&weapon1;
};

#endif
