/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:18:29 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 07:18:30 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{

private:
        
        Enemy();
        Enemy(Enemy const &src);

public:
		Enemy(int hp, std::string const &type);
		Enemy 			&operator=(Enemy const &src);
		virtual ~Enemy();

		std::string		getType() const;
		int 			getHP() const;
		virtual void 	takeDamage(int dmg);

		int				_hp;
		std::string 	_type;
		std::string 	_birth;
		std::string		_death;
 };

 #endif
