/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_spoint		to_next_row(t_spoint c)
{
	c.c = 0;
	c.r++;
	return (c);
}

int				short_check(char **dest, char *src, t_spoint c, t_spoint k)
{
	t_spoint	n;

	n.r = 0;
	n.c = tetra_num(src);
	while (n.r <= n.c - 1)
	{
		while (dest[c.r])
		{
			while (dest[c.r][c.c])
			{
				if (dest[c.r][c.c] == 'A' + n.r)
					k.r++;
				c.c++;
			}
			c = to_next_row(c);
		}
		if (k.r == 4)
			k.c++;
		k.r = 0;
		c.r = 0;
		n.r++;
	}
	return (k.c);
}

int				check_alpha(char **dest, char *src)
{
	t_spoint	c;
	t_spoint	k;
	int			i;
	int			j;

	c.r = 0;
	c.c = 0;
	k.r = 0;
	k.c = 0;
	i = short_check(dest, src, c, k);
	j = tetra_num(src);
	if (i == j)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
