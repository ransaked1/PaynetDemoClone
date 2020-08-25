/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:15:51 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:15:56 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_help(t_data *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= 270)
	{
		j = -1;
		while (++j <= 225)
		{
			if (i == 0 || i == 270 || j == 0 || j == 225)
				mlx_pixel_put(e->mlx, e->win, i, j, B);
			else
				mlx_pixel_put(e->mlx, e->win, i, j, 0x33FFFFFF);
		}
	}
	mlx_string_put(e->mlx, e->win, 13, 10, B, "MOVE: arrow keys");
	mlx_string_put(e->mlx, e->win, 13, 30, B, "ZOOM: +<->-, mouse wheel");
	mlx_string_put(e->mlx, e->win, 13, 50, B, "PARAM1 MODIFY: Q<->W");
	mlx_string_put(e->mlx, e->win, 13, 70, B, "PARAM2 MODIFY: E<->R");
	mlx_string_put(e->mlx, e->win, 13, 90, B, "SATURATION MODIFY: Z<->X");
	mlx_string_put(e->mlx, e->win, 13, 110, B, "COLOR MODIFY: C<->V D<->F");
	mlx_string_put(e->mlx, e->win, 13, 130, B, "RESET IMAGE: 0");
	mlx_string_put(e->mlx, e->win, 13, 150, B, "CHANGE_MODE ON/OFF: M");
	mlx_string_put(e->mlx, e->win, 13, 170, B, "HELP ON/OFF: H");
	mlx_string_put(e->mlx, e->win, 13, 190, B, "EXIT: escape key");
}

char	*info_color(int i)
{
	if (i == 0)
		return ("red");
	if (i == 1)
		return ("orange");
	if (i == 2)
		return ("yellow");
	if (i == 3)
		return ("green");
	if (i == 4)
		return ("cyan");
	if (i == 5)
		return ("blue");
	if (i == 6)
		return ("indigo");
	if (i == 7)
		return ("violet");
	return ("unidentified");
}

void	get_info(t_data *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= e->f.w)
	{
		j = -1;
		while (++j <= 40)
		{
			if (i == 0 || i == e->f.w || j == 0 || j == 40)
				mlx_pixel_put(e->mlx, e->win, i, e->f.h - j, B);
			else
				mlx_pixel_put(e->mlx, e->win, i, e->f.h - j, 0xAAFFFFFF);
		}
	}
	mlx_string_put(e->mlx, e->win, 30, e->f.h - 30, B, "saturation = ");
	mlx_string_put(e->mlx, e->win, 160, e->f.h - 30, B,
		ft_itoa((e->f.cs + 16) / 16 - 1));
	mlx_string_put(e->mlx, e->win, 230, e->f.h - 30, B, "color = ");
	mlx_string_put(e->mlx, e->win, 310, e->f.h - 30, B,
		info_color((e->f.ch + 32) / 32 - 1));
	mlx_string_put(e->mlx, e->win, 400, e->f.h - 30, B, "color range = ");
	mlx_string_put(e->mlx, e->win, 540, e->f.h - 30, B, ft_itoa(e->f.chr));
}

void	draw(t_data e, int x, int y, int color)
{
	int		i;
	int		index;
	t_col	col;

	i = 0;
	index = e.lsize * y + x * BPP - 1;
	col = sep_color(color);
	e.img_add[index + 3] = col.r;
	e.img_add[index + 2] = col.g;
	e.img_add[index + 1] = col.b;
}

void	print_fractol(char c, t_data data)
{
	if (c == 'J')
		julia(data, data.f);
	if (c == 'M')
		mandelbrot(data, data.f);
	if (c == 'B')
		burning_ship(data, data.f);
	mlx_clear_window(data.mlx, data.win);
	mlx_put_image_to_window(data.mlx, data.win, data.img, data.stx, data.sty);
	get_info(&data);
}
