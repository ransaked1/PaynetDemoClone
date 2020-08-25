/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_block1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_sqrt(int nb)
{
	int			i;
	int			sq;

	i = 0;
	sq = 0;
	while (i <= nb / 2)
	{
		sq = i * i;
		if (sq >= nb)
			return (i);
		i++;
	}
	return (0);
}

int				condition1(char **dest, int n, t_spoint c)
{
	if (((dest[c.r][c.c] != ('A' + n)) &&
				(dest[c.r + 1][c.c] == 'A' + n) &&
				(dest[c.r][c.c + 2] == 'A' + n)) ||
			((dest[c.r][c.c] != ('A' + n)) &&
			(dest[c.r + 2][c.c] == 'A' + n) &&
			(dest[c.r][c.c + 1] == 'A' + n)) ||
			((dest[c.r][c.c] != ('A' + n)) &&
			(dest[c.r + 1][c.c] == 'A' + n) &&
			(dest[c.r][c.c + 1] == 'A' + n)) ||
			(dest[c.r][c.c] == 'A' + n))
		return (1);
	else
		return (0);
}

int				condition2(char **dest, int n, t_spoint c)
{
	if ((dest[c.r][c.c] == 'A' + n) ||
			(dest[c.r][c.c] != ('A' + n) &&
			(dest[c.r][c.c + 1] == 'A' + n) &&
			(dest[c.r + 1][c.c] == 'A' + n)) ||
			(dest[c.r][c.c] != ('A' + n) &&
			(dest[c.r + 1][c.c] == 'A' + n) &&
			(dest[c.r][c.c + 2] == 'A' + n)))
		return (1);
	else
		return (0);
}

t_spoint		short_find(char **dest, int n, t_spoint c)
{
	int			i;

	i = (int)ft_strlen(dest[0]) - 1;
	while (c.r <= i)
	{
		while (dest[c.r][c.c])
		{
			if (c.r <= (i - 2))
			{
				if (condition1(dest, n, c) == 1)
					return (c);
			}
			else if (c.r == i)
			{
				if (dest[c.r][c.c] == 'A' + n)
					return (c);
			}
			else if (condition2(dest, n, c) == 1)
				return (c);
			c.c++;
		}
		c = to_next_row(c);
	}
	return (c);
}

t_spoint		find(char **dest, int n)
{
	t_spoint	c;

	c.r = 0;
	c.c = 0;
	c = short_find(dest, n, c);
	return (c);
}
