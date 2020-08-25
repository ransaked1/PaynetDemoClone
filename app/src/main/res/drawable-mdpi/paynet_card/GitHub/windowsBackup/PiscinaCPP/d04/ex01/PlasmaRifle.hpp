/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:17:50 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:17:55 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class PlasmaRifle : public AWeapon
{

public:

	PlasmaRifle();
	~PlasmaRifle();
	
	virtual void 	attack() const;
};

#endif
