/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_block2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_spoint		restart(t_spoint c)
{
	c.c = 0;
	c.r = 0;
	return (c);
}

t_spoint		ft_iterate(char **dest, t_spoint c)
{
	int i;

	i = (int)ft_strlen(dest[0]) - 1;
	c.c++;
	if (c.c > i)
	{
		c.r++;
		c.c = 0;
	}
	return (c);
}

t_spoint		delete_iterate(char **dest, int n, t_spoint c)
{
	del_tetra(dest, n);
	c = ft_iterate(dest, c);
	return (c);
}

t_spoint		iterate_delete(char **dest, int n, t_spoint c)
{
	t_spoint	d;

	d = find(dest, n);
	c = ft_iterate(dest, d);
	del_tetra(dest, n);
	return (c);
}

int				check_a(char **d)
{
	t_spoint	x;
	t_spoint	a;

	x.c = 0;
	x.r = (int)ft_strlen(d[0]) - 1;
	a.r = 0;
	a.c = 0;
	while (d[x.r][x.c])
	{
		if (d[x.r][x.c] == 'A')
			a.c++;
		x.c++;
	}
	x.c = 0;
	x.r--;
	while (d[x.r][x.c])
	{
		if (d[x.r][x.c] == 'A')
			a.r++;
		x.c++;
	}
	if (a.c < 4 && a.c >= 1 && a.r == 0)
		return (1);
	else
		return (0);
}
