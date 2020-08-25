/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 05:31:57 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 05:31:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{

public:

	Peon(void);
	Peon(std::string name);
	Peon(Peon const &src);
	Peon &operator=(Peon const &src);
	~Peon(void);
	
	virtual void		getPolymorphed(void) const;
};

#endif
