/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 19:19:51 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/24 19:19:53 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

class ZombieHorde
{

public:

	ZombieHorde(int n);
	~ZombieHorde();
	
	void	announce(void);

private:
	std::string		_name;
	Zombie 			*zombieHorde;
	int				N;
};

#endif