/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:20:43 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:20:44 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Enemy.hpp"
#include <iostream>
#include <cstdlib>
#include "AWeapon.hpp"

class Character
{

private:

        Character(void);
        Character(Character const &src);

public:

		Character(std::string const &name);
		//Character &operator=(Character const &src);
		~Character();
		void recoverAP();
		void equip(AWeapon *wp);
		void attack(Enemy *e);
		std::string getName() const;
		std::string getAP() const;
		std::string getWeapon() const;

		std::string		_name;
		int				_ap;
		AWeapon 		*w;
};

std::ostream	&operator<<(std::ostream &o, Character const &src);

#endif