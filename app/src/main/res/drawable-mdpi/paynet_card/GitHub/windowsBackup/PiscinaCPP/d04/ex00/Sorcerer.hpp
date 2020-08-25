/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 05:31:03 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 05:31:05 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{

public:

	Sorcerer(void);
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const &src);
	Sorcerer &operator=(Sorcerer const &src);
	~Sorcerer(void);

	std::string		getName(void) const;
	std::string 	getTitle(void) const;
	void 			polymorph(Victim const &src);

private:

	std::string		_name;
	std::string		_title;
};

std::ostream	&operator<<(std::ostream &o, Sorcerer const &src); 

#endif
