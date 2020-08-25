/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:57:51 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 16:59:01 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			rownum(int fd)
{
	int		i;
	char	c;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	return (i);
}

char		**ft_split(char **tab, int i)
{
	char **tab2;

	tab2 = ft_strsplit(tab[i], ' ');
	return (tab2);
}

int			rowlen(char **tab)
{
	char	**tab2;
	int		i;

	i = 0;
	tab2 = ft_split(tab, 0);
	while (tab2[i])
		i++;
	return (i - 1);
}

t_pixel		ft_start(char **argv, char **tab, t_pixel *ptab)
{
	int			pixels;
	t_pixel		p;
	int			i;

	pixels = rownum(open(argv[1], O_RDONLY)) * (rowlen(tab) + 1);
	i = rowlen(tab);
	p.j = 0;
	p.x = 0;
	p.y = 0;
	p.dx = 2;
	p.dy = 1;
	p.dh = 1;
	p.sdh = 0;
	p.c = pixels;
	p.column = i + 1;
	p.width = 1280;
	p.height = 720;
	write_pixel(ptab, p, tab);
	p = open_window(ptab, p);
	write_pixel(ptab, p, tab);
	return (p);
}
