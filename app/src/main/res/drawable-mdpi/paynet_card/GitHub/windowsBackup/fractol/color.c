/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:16:10 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:16:13 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_col	sep_color(int col)
{
	t_col	c;

	c.b = col % 256;
	col -= c.b;
	c.g = (col % 65536) / 256;
	col -= c.g;
	c.r = (col % 16777216) / 65536;
	return (c);
}

int		hsvtorgb(float h, float s, float v)
{
	INT0(hex);
	FLOAT0(mm, m, z, r, g, b);
	r = 0;
	g = 0;
	b = 0;
	mm = 255 * v / 255;
	m = mm * (1 - s / 255);
	z = (mm - m) * (1 - floatabs(f_mod(h) - 1));
	if ((h >= 0 && h < 60) || (h >= 300 && h < 360))
		r = mm;
	else
		r = (h >= 120 && h < 240) ? m : (z + m);
	if ((h >= 0 && h < 60) || (h >= 180 && h < 240))
		g = z + m;
	else
		g = (h >= 240 && h < 360) ? m : mm;
	if ((h >= 0 && h < 120))
		b = m;
	else
		b = (h >= 180 && h < 300) ? mm : (z + m);
	r = (int)rnd(r);
	g = (int)rnd(g);
	b = (int)rnd(b);
	hex = r * 65536 + g * 256 + b;
	return (hex);
}

int		get_hue(int start, int range, int i)
{
	int		res;
	int		val;

	res = 0;
	val = i % range;
	if ((i / range) % 2 == 0)
		res = start + val;
	else
		res = start + range - val;
	return (res);
}
