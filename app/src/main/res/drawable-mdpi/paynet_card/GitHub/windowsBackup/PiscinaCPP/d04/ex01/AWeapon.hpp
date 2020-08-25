/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:17:22 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:17:23 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
#include "Enemy.hpp"

class AWeapon
{

private:

	AWeapon(void);
	AWeapon(AWeapon const &src);

public:
	AWeapon(std::string const &name, int apcost, int damage);
	virtual ~AWeapon(void);
	//Weapon &operator=(Weapon const &src);

	std::string 	getName() const;
	int 			getAPCost() const;
	int 			getDamage() const;
    virtual void 	attack() const = 0;

    std::string		_outAttack;
    std::string		_name;
	int				_dmg;
	int				_ap;
};

#endif
