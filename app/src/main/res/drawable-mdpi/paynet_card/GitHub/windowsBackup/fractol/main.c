/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:17:00 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:17:03 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_fractol(void)
{
	ft_putstr("\033[0;31mInvalid fractol name!\n");
	ft_putstr("\033[0m--------------------\n");
	ft_putstr("\033[0mAvailable fractols:\n");
	ft_putstr("\033[1;37mJulia\033[0m = \033[0;32mJ\n");
	ft_putstr("\033[1;37mMandebrot\033[0m = \033[0;32mM\n");
	ft_putstr("\033[1;37mBurning ship\033[0m = \033[0;32mB\n");
	ft_putstr("\033[0m--------------------\n");
}

void	init_fr(t_data *d)
{
	d->f.pre = -0.7;
	d->f.pim = 0.27015;
	d->f.maxit = 360;
	d->f.zoom = 1;
	d->f.movex = (d->fr_type == 'M') ? -1 : 0;
	if (d->fr_type != 'M')
		d->f.movex = (d->fr_type == 'B') ? -0.5 : 0;
	d->f.movey = (d->fr_type == 'B') ? -0.5 : 0;
	d->f.cs = 0;
	d->f.ch = 0;
	d->f.chr = 40;
}

t_data	init(char *str, void *mlx)
{
	t_data	d;

	d.mlx = mlx_init();
	d.f.w = 600;
	d.f.h = 400;
	d.help = 1;
	d.ch_mode = 0;
	d.fr_type = str[0];
	d.win = mlx_new_window(mlx, d.f.w, d.f.h, str);
	d.img = mlx_new_image(mlx, d.f.w, d.f.h);
	d.bpp = BPP;
	d.end = 0;
	d.img_add = mlx_get_data_addr(d.img, &d.bpp, &d.lsize, &d.end);
	d.stx = 0;
	d.sty = 0;
	init_fr(&d);
	return (d);
}

void	main_fr(int ac, char **a, t_allfr all)
{
	if (a[1][0] == 'J' || a[1][0] == 'M' || a[1][0] == 'B')
	{
		all.data1 = init(a[1], all.mlx);
		print_fractol(a[1][0], all.data1);
		mlx_key_hook(all.data1.win, key_hook, &all.data1);
		mlx_mouse_hook(all.data1.win, mouse_hook, &all.data1);
		mlx_hook(all.data1.win, MT_NOT, MT_MASK, motion_hook, &all.data1);
	}
	if (ac >= 3 && (a[2][0] == 'J' || a[2][0] == 'M' || a[2][0] == 'B'))
	{
		all.data2 = init(a[2], all.mlx);
		print_fractol(a[2][0], all.data2);
		mlx_key_hook(all.data2.win, key_hook, &all.data2);
		mlx_mouse_hook(all.data2.win, mouse_hook, &all.data2);
		mlx_hook(all.data2.win, MT_NOT, MT_MASK, motion_hook, &all.data2);
	}
	if (ac >= 4 && (a[3][0] == 'J' || a[3][0] == 'M' || a[3][0] == 'B'))
	{
		all.data3 = init(a[3], all.mlx);
		print_fractol(a[3][0], all.data3);
		mlx_key_hook(all.data3.win, key_hook, &all.data3);
		mlx_mouse_hook(all.data3.win, mouse_hook, &all.data3);
		mlx_hook(all.data3.win, MT_NOT, MT_MASK, motion_hook, &all.data3);
	}
}

int		main(int ac, char **a)
{
	t_allfr	all;

	if (ac >= 2 && (a[1][0] == 'J' || a[1][0] == 'M' || a[1][0] == 'B'))
	{
		all.mlx = mlx_init();
		main_fr(ac, a, all);
		mlx_loop(all.mlx);
	}
	else
		help_fractol();
	return (0);
}
