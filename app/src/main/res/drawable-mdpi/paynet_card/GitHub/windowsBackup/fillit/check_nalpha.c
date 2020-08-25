/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				short_ncheck(char **dest, t_spoint c, t_spoint k)
{
	while (dest[c.r])
	{
		while (dest[c.r][c.c])
		{
			if (dest[c.r][c.c] == 'A' + k.c)
				k.r++;
			c.c++;
		}
		c.c = 0;
		c.r++;
	}
	return (k.r);
}

int				check_nalpha(char **dest, int n)
{
	t_spoint	c;
	t_spoint	k;
	int			i;

	c.r = 0;
	c.c = 0;
	k.r = 0;
	k.c = n;
	i = short_ncheck(dest, c, k);
	if (i == 4)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
