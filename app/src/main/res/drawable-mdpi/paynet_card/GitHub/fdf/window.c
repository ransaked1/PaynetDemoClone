/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:01:44 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 17:02:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			miny(t_pixel *ptab, t_pixel start)
{
	int min;
	int i;

	min = ptab[0].y;
	i = 0;
	while (i < start.c)
	{
		if (ptab[i].y < min)
			min = ptab[i].y;
		i++;
	}
	return (min);
}

t_pixel		strt(t_pixel start, int x)
{
	start.x = 0;
	start.dx = 3 * x;
	start.dy = 1 * x;
	if (start.c < 25000)
	{
		start.width = 1280;
		start.height = 720;
	}
	else
	{
		start.width = 1920;
		start.height = 1080;
	}
	return (start);
}

t_pixel		open_window(t_pixel *ptab, t_pixel start)
{
	int		tmp;

	tmp = 1;
	if (start.c < 1000)
	{
		tmp = 10;
		start.dh = 3;
		start.sdh = start.dh;
		start.y = 300;
	}
	else
	{
		start.y = ft_abs(miny(ptab, start)) + 10;
		start.sy = start.y;
		start.sdh = start.dh;
	}
	free(ptab);
	ptab = ft_memalloc(10000000);
	ptab[0].x = 78036426;
	start = strt(start, tmp);
	return (start);
}
