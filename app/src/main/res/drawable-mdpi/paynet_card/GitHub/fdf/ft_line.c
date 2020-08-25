/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:05:20 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 17:30:12 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_col	take_color(int col)
{
	t_col	c;

	c.b = col % 256;
	c.g = (col - c.b) % 65536 / 256;
	c.r = (col - c.g) % 16777216 / 65536;
	return (c);
}

int		get_col(int col1, int col2, int max, int i)
{
	t_col	c1;
	t_col	c2;
	int		rez;

	c1 = take_color(col1);
	c2 = take_color(col2);
	rez = (col1 < col2) ? col1 : col2;
	max += 2;
	if (c1.r != c2.r)
		rez = col_r(c1, c2, max, i) * 65536;
	if (c1.g != c2.g)
		rez += col_g(c1, c2, max, i) * 256;
	if (c1.b != c2.b)
		rez += col_b(c1, c2, max, i);
	return (rez);
}

void	normdraw(int *i, float *x, float *y, t_pixel p)
{
	*i = 1;
	*x = p.x;
	*y = p.y;
}

void	draw(t_pixel d, t_data data, t_pixel p1, t_pixel p2)
{
	int		i;
	int		max;
	float	x;
	float	y;

	normdraw(&i, &x, &y, p1);
	max = (d.y > d.x) ? d.y : d.x;
	while (i <= max)
	{
		data.global_col == 1 ? mlx_pixel_put(data.mlx_ptr, data.mlx_win,
				rund(x), rund(y), W) : mlx_pixel_put(data.mlx_ptr, data.mlx_win,
				rund(x), rund(y), get_col(p1.c, p2.c, max, i));
		if (d.x < d.y)
		{
			x = (p1.x < p2.x) ? (p1.x + d.x / d.y * i) : (p1.x - d.x / d.y * i);
			(p1.y < p2.y) ? ++y : --y;
		}
		else
		{
			y = (p1.y < p2.y) ? (p1.y + d.y / d.x * i) : (p1.y - d.y / d.x * i);
			(p1.x < p2.x) ? ++x : --x;
		}
		i++;
	}
}

void	line(t_data data, t_pixel p1, t_pixel p2)
{
	t_pixel	d;
	int		max;

	d.x = ft_abs((int)(p1.x - p2.x));
	d.y = ft_abs((int)(p1.y - p2.y));
	max = d.y > d.x ? d.y : d.x;
	if (max == 0)
	{
		d.x = 0;
		d.y = 0;
		draw(d, data, p1, p2);
	}
	else
		draw(d, data, p1, p2);
}
