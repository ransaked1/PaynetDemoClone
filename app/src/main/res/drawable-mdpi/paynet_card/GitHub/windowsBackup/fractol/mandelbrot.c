/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:15:33 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:15:39 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_data data, t_fract f, int x, int y)
{
	DOUBLE0(newre, newim, oldre, oldim, pr, pi);
	INT0(h, v, i);
	pr = 1.5 * (x - f.w / 2) / (0.5 * f.zoom * f.w) + f.movex;
	pi = (y - f.h / 2) / (0.5 * f.zoom * f.h) + f.movey;
	newre = 0;
	newim = 0;
	i = -1;
	while (++i < f.maxit)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + pr;
		newim = 2 * oldre * oldim + pi;
		if ((newre * newre + newim * newim) > 4)
			break ;
	}
	h = get_hue(f.ch, f.chr, i);
	v = get_hue(55, 200, i);
	draw(data, x, y, hsvtorgb(h % 360, f.cs, v));
}

void	mandelbrot(t_data data, t_fract f)
{
	INT0(x, y);
	y = -1;
	while (++y < f.h)
	{
		x = -1;
		while (++x < f.w)
		{
			draw_mandelbrot(data, f, x, y);
		}
	}
	mlx_clear_window(data.mlx, data.win);
	mlx_put_image_to_window(data.mlx, data.win, data.img, data.stx, data.sty);
}
