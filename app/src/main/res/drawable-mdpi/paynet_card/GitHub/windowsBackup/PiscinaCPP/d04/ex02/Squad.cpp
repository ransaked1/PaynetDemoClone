/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:58:43 by dbraghis          #+#    #+#             */
/*   Updated: 2017/07/26 10:58:44 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "TacticalMarine.hpp"

Squad::Squad()
{
	this->squad = new ISpaceMarine*[1];
	this->nr = 0;
	return ;
}

Squad::~Squad()
{
	int		i;
	for (i = 0; i < nr; i++)
		delete this->squad[i];
}

Squad::Squad(Squad const &src)
{
	*this = src;
	this->squad = src.squad;
	this->nr = src.nr;
	return ;
}

int		Squad::getCount() const
{
	return (this->nr);
}

ISpaceMarine	*Squad::getUnit(int n) const
{
	return (this->squad[n]);
}

int				Squad::push(ISpaceMarine *marine)
{
	int		i;

	if (marine == NULL)
		return 0;

	for (i = 0; i < this->nr; i++)
	{
		if (squad[i] == marine)
			return (this->nr);
	}

	ISpaceMarine **newSquad = new ISpaceMarine*[this->nr + 1];
	for (i = 0; i < this->nr; i++)
	{
		newSquad[i] = squad[i];
	}
	newSquad[i] = marine;
	this->nr += 1;
	delete [] squad;
	squad = newSquad;
	return (this->nr);
}