/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:03:31 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 17:51:31 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_reset(t_data *data)
{
	data->start.dh = data->start.sdh;
	data->start.x = 0;
	if (data->start.c < 1000)
		data->start.y = 300;
	else
		data->start.y = data->start.sy;
	data->global_col = 0;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ft_draw(*data, data->start);
}

void	hook_nocol(t_data *data)
{
	data->global_col = (data->global_col == 0) ? 1 : 0;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ft_draw(*data, data->start);
}

void	hook_move(int k, t_data *data)
{
	int		i;

	i = 1;
	if (data->start.c > 3000)
		i = 20;
	if (k == RIGHT)
		data->start.x += 10 * i;
	if (k == LEFT)
		data->start.x -= 10 * i;
	if (k == DOWN)
		data->start.y += 10 * i;
	if (k == UP)
		data->start.y -= 10 * i;
	if (k == D)
		data->start.dh = (data->start.dh == 0) ? data->start.sdh : 0;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ft_draw(*data, data->start);
}

void	get_help(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win,
			15, 10, V, "MOVE - AROW KEYS");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
			15, 30, V, "ADD/REMOVE COLOR - 'C'");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
			15, 50, V, "3D and 2D - 'D'");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
			15, 90, V, "HELP - OTHER KEYS");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
			15, 70, V, "RESET TO ORIGINAL - 'R'");
	mlx_string_put(data->mlx_ptr, data->mlx_win,
			15, 110, V, "END - ESCAPE ");
}

int		key_hook(int k, void *data)
{
	t_data	*d;

	d = data;
	if (k == RIGHT || k == LEFT || k == DOWN || k == UP || k == D)
		hook_move(k, d);
	if (k == C)
		hook_nocol(d);
	if (k == RESET)
		hook_reset(d);
	if (k == ESC)
		exit(0);
	get_help(data);
	return (0);
}
