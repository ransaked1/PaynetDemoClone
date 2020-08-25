/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhooks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:17:14 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:17:17 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_data *e)
{
	print_fractol(e->fr_type, *e);
	return (0);
}

int		motion_hook(int x, int y, t_data *e)
{
	if (e->fr_type == 'J')
	{
		if (e->ch_mode == 1)
		{
			e->f.pim = 0.27015 + x * 0.0001 / e->f.zoom;
			e->f.pre = -0.7 + y * 0.0001 / e->f.zoom;
			print_fractol(e->fr_type, *e);
		}
	}
	return (0);
}

void	zoom(int button, int x, int y, t_data *e)
{
	FLOAT0(midw, midh);
	midw = (float)e->f.w / 2;
	midh = (float)e->f.h / 2;
	e->f.zoom *= (button == 4) ? 1.1 : 1;
	if (button == 4)
		e->f.movex += (x > midw) ? (0.0005 * floatabs(x - midw) / e->f.zoom) :
								(-0.0005 * floatabs(x - midw) / e->f.zoom);
	if (button == 4)
		e->f.movey += (y > midh) ? (0.0005 * floatabs(y - midh) / e->f.zoom) :
								(-0.0005 * floatabs(y - midh) / e->f.zoom);
	if (button == 5)
		e->f.movex -= (x > midw) ? (0.0005 * floatabs(x - midw) / e->f.zoom) :
									(-0.0005 * floatabs(x - midw) / e->f.zoom);
	if (button == 5)
		e->f.movey -= (y > midh) ? (0.0005 * floatabs(y - midh) / e->f.zoom) :
									(-0.0005 * floatabs(y - midh) / e->f.zoom);
	e->f.zoom /= (button == 5) ? 1.1 : 1;
}

int		mouse_hook(int button, int x, int y, void *data)
{
	t_data		*e;

	e = data;
	zoom(button, x, y, e);
	if (button == 4 || button == 5)
		print_fractol(e->fr_type, *e);
	return (0);
}
