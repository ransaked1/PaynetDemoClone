/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:18:10 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:18:11 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class PowerFist : public AWeapon
{

public:

	PowerFist();
	~PowerFist();
	
	virtual void 	attack() const;
};

#endif
