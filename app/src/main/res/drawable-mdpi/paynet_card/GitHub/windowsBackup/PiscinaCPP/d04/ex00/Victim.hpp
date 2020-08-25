/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 05:31:38 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 05:31:39 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{

public:

	Victim(void);
	Victim(std::string name);
	Victim(Victim const &src);
	Victim &operator=(Victim const &src);
	~Victim(void);
	
	std::string		getName(void) const;
	virtual void			getPolymorphed() const;

	std::string		_name;
};

std::ostream	&operator<<(std::ostream &o, Victim const &src); 

#endif
