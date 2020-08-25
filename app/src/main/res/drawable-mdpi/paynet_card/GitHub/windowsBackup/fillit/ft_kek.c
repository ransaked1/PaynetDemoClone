/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kek.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:43:23 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/28 19:09:41 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		short_kek(char *tab, t_spoint r, t_spoint v)
{
	while (tab[r.c])
	{
		if (tab[r.c] == '%')
		{
			r.r++;
			v.r++;
		}
		if (tab[r.c] == '%' && tab[r.c + 1] == '\n')
		{
			if (v.r != 4)
				return (0);
			v.c++;
			v.r = 0;
		}
		r.c++;
	}
	if (r.r != tetra_num(tab) * 4 || (tetra_num(tab) != v.c))
		return (0);
	else
		return (1);
}

int		ft_kek2(char *tab)
{
	int			i;
	t_spoint	r;
	t_spoint	v;

	i = 0;
	r.c = 0;
	r.r = 0;
	v.r = 0;
	v.c = 0;
	i = short_kek(tab, r, v);
	return (i);
}

int		ft_kek1(char *btab, char *tab)
{
	int		i;
	int		p;
	int		m;

	i = 0;
	p = 0;
	m = 0;
	if (tab[0] == '\0')
		return (0);
	while (tab[i])
	{
		if (tab[i] != '.' && tab[i] != '#' &&
				tab[i] != '%' && tab[i] != '\n')
			return (0);
		if (tab[i] == '.')
			p++;
		if (tab[i] == '#')
			m++;
		i++;
	}
	if (((btab[i - 2] != '.' && btab[i - 2] != '#') && btab[i - 1] !=
			'\0') || m != tetra_num(tab) * 4 || (p != tetra_num(tab) * 12))
		return (0);
	else
		return (1);
}

int		ft_kek(char *btab, char *tab)
{
	if (ft_kek1(btab, tab) && ft_kek2(tab))
		return (1);
	else
		return (0);
}
