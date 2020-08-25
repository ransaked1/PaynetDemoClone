/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_put_tetra(char **dest, char *src, int n, t_spoint c)
{
	t_spoint	p;
	int			x;
	char		**tab;

	p.r = 0;
	p.c = 0;
	x = c.c;
	tab = isolate(src, n);
	while (tab[p.r] && dest[c.r])
	{
		while (tab[p.r][p.c] && dest[c.r][c.c])
		{
			if (tab[p.r][p.c] >= 'A' &&
				tab[p.r][p.c] <= 'Z' && dest[c.r][c.c] == '.')
				dest[c.r][c.c] = tab[p.r][p.c];
			p.c++;
			c.c++;
		}
		p.c = 0;
		c.c = x;
		p.r++;
		c.r++;
	}
}
