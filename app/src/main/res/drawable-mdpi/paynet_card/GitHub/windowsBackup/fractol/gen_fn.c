/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_fn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:16:25 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:16:27 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rnd(float nb)
{
	float	x;
	int		res;

	res = (int)nb;
	x = nb - res;
	if (nb > 0)
	{
		if (x >= 0.5)
			return (++res);
		return (res);
	}
	if (x <= -0.5)
		return (--res);
	return (res);
}

float	floatabs(float x)
{
	if (x <= 0)
		return (-x);
	else
		return (x);
}

float	f_mod(float h)
{
	float x;
	float y;
	float j;

	x = h / 60;
	y = (int)x / 2;
	j = x - y * 2;
	return (j);
}
