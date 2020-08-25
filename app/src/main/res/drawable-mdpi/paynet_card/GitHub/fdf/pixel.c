/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:00:10 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 17:01:02 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	put_pixel(char *tmp, t_pixel origin, int ordine, int rang)
{
	t_pixel	p;
	char	*ptr;
	int		h;

	h = 0;
	h = ft_atoi(tmp);
	p.x = origin.x + origin.dx * rang + (ordine / origin.column) * origin.dx;
	p.y = origin.y - origin.dy * rang +
	(ordine / origin.column) * origin.dy - h * (origin.dh);
	if ((ptr = ft_strchr(tmp, ',')))
		p.c = c_atoi(++ptr);
	else
		p.c = W;
	return (p);
}

void	add_pixel(t_pixel *ptab, t_pixel start, char **temp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ptab[i].x != 78036426)
		i++;
	while (temp[j])
	{
		ptab[i] = put_pixel(temp[j], start, i, j);
		i++;
		j++;
	}
	ptab[i].x = 78036426;
}

void	write_pixel(t_pixel *ptab, t_pixel p, char **tab)
{
	int		i;
	char	**tmp;

	i = 0;
	while (tab[i])
	{
		tmp = ft_split(tab, i);
		add_pixel(ptab, p, tmp);
		free(tmp);
		i++;
	}
}
