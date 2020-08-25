/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:01:09 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 17:01:40 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		drawit(t_data data, t_pixel *ptab, t_pixel start)
{
	while (start.j < start.c)
	{
		if ((start.j + 1) % (start.column) != 0)
			line(data, ptab[start.j], ptab[start.j + 1]);
		if (start.j + start.column < start.c)
			line(data, ptab[start.j], ptab[start.j + start.column]);
		start.j++;
	}
}

void		ft_draw(t_data data, t_pixel start)
{
	data.ptab[0].x = 78036426;
	data.start = start;
	write_pixel(data.ptab, start, data.tab);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	drawit(data, data.ptab, data.start);
	mlx_loop(data.mlx_ptr);
}
