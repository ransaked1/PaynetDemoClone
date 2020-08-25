/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:59:08 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 17:00:03 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rund(float nb)
{
	float	x;
	int		rez;

	rez = (int)nb;
	x = nb - rez;
	if (nb > 0)
	{
		if (x >= 0.5)
			return (++rez);
		return (rez);
	}
	if (x <= -0.5)
		return (--rez);
	return (rez);
}

int		ft_abs(int i)
{
	if (i <= 0)
		return (-i);
	return (i);
}

int		error(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_pixel		start;
	int			k;

	k = 0;
	if (!error(argc, argv))
		return (0);
	data.ptab = ft_memalloc(100000000);
	data.ptab[0].x = 78036426;
	data.tab = read_tab(argc, argv);
	start = ft_start(argv, data.tab, data.ptab);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr,
		start.width, start.height, "FDF");
	ft_draw(data, start);
}
