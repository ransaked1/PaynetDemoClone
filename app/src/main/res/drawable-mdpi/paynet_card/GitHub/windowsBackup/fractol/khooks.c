/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   khooks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:16:43 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:16:48 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_move_zoom(int k, t_data *d)
{
	d->f.movex += (k == 123) ? (0.3 / d->f.zoom) : 0;
	d->f.movex -= (k == 124) ? (0.3 / d->f.zoom) : 0;
	d->f.movey -= (k == 125) ? (0.3 / d->f.zoom) : 0;
	d->f.movey += (k == 126) ? (0.3 / d->f.zoom) : 0;
	d->f.zoom *= (k == 24) ? 2 : 1;
	d->f.zoom /= (k == 27) ? 2 : 1;
	if (k == 46)
		d->ch_mode = (d->ch_mode == 1) ? 0 : 1;
	print_fractol(d->fr_type, *d);
}

void	hook_change_param(int k, t_data *d)
{
	d->f.pim += (k == 12) ? 0.0002 : 0;
	d->f.pim -= (k == 13) ? 0.0002 : 0;
	d->f.pre += (k == 14) ? 0.0002 : 0;
	d->f.pre -= (k == 15) ? 0.0002 : 0;
	if (k == 29)
	{
		d->f.pre = -0.7;
		d->f.pim = 0.27015;
		d->f.zoom = 1;
		d->f.movex = (d->fr_type == 'M') ? -1 : 0;
		d->f.movex = (d->fr_type == 'B') ? -0.5 : 0;
		d->f.movey = (d->fr_type == 'B') ? -0.5 : 0;
		d->f.cs = 0;
		d->f.ch = 0;
		d->f.chr = 40;
		d->stx = 0;
		d->sty = 0;
	}
	print_fractol(d->fr_type, *d);
}

void	hook_color(int k, t_data *d)
{
	if (k == 6)
		d->f.cs -= (d->f.cs - COL_STEP >= 0) ? COL_STEP : 0;
	if (k == 7)
		d->f.cs += (d->f.cs + COL_STEP < 256) ? COL_STEP : 0;
	if (k == 8)
		d->f.ch -= (d->f.ch - COL_STEP * 2 >= 0) ? (COL_STEP * 2) : 0;
	if (k == 9)
		d->f.ch += (d->f.ch + COL_STEP * 2 < 256) ? (COL_STEP * 2) : 0;
	if (k == 2)
		d->f.chr -= (d->f.chr - 10 > 0) ? 10 : 0;
	if (k == 3)
		d->f.chr += (d->f.chr + 10 < 256) ? 10 : 0;
	print_fractol(d->fr_type, *d);
}

int		key_hook(int k, void *data)
{
	t_data	*d;

	d = data;
	if (k == 53)
		exit(0);
	if ((k >= 123 && k <= 126) || k == 24 || k == 27 || k == 46)
		hook_move_zoom(k, d);
	if ((k >= 12 && k <= 15) || k == 29)
		hook_change_param(k, d);
	if ((k >= 6 && k <= 9) || k == 2 || k == 3)
		hook_color(k, d);
	if (k == 4)
	{
		if (d->help == 1)
			get_help(d);
		else
			print_fractol(d->fr_type, *d);
		d->help = (d->help == 1) ? 0 : 1;
	}
	return (0);
}
