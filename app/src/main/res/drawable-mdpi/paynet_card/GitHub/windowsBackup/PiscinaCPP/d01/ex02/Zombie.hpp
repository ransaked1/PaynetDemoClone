/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:07:13 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 15:07:15 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{

public:

	Zombie(void);
	~Zombie(void);
	
	void		setType(std::string type);
	void		setName(std::string name);

	void		announce(void);

private:
	std::string		_type;
	std::string		_name;

};

#endif
