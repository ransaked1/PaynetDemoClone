/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:58:37 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 10:58:39 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <cstdlib>

class Squad : public ISquad
{

public:

	~Squad();
	Squad(void);
	Squad(Squad const &src);
	int 			getCount() const;
	ISpaceMarine 	*getUnit(int n) const;
	int 			push(ISpaceMarine *marine);

	int				nr;
	ISpaceMarine	**squad;
};

#endif