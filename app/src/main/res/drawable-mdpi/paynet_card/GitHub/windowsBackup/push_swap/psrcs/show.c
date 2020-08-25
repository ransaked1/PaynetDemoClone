/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:45:08 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:45:10 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_bufset(void)
{
	int		n;

	n = 0;
	while (n < 5000)
	{
		g_buf[n] = '\0';
		n++;
	}
	g_i = 0;
}

void		ft_display(void)
{
	write(1, g_buf, g_i - 1);
	if (g_i < 5000)
		ft_putchar('\n');
	ft_bufset();
}

void		ft_buf(char *str, t_lst *a, t_lst *b)
{
	t_elem		*oops;
	t_elem		*ops;

	ops = a->head;
	oops = b->head;
	ft_strcat(g_buf, str);
	if (ft_strlen(str) == 4)
		g_i++;
	g_i = g_i + 3;
	if (g_i >= 4092)
		ft_display();
}
