/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			short_solve(char **dest, char *src, int n, t_spoint c)
{
	t_spoint	j;

	j.r = 0;
	while ((check_alpha(dest, src) == 0) && (j.r == 0))
	{
		ft_put_tetra(dest, src, n, c);
		j.r = check_a(dest);
		if (check_nalpha(dest, n) == 0)
		{
			if (n == 0 && c.r == 0 && c.c == 0)
				return ;
			c = delete_iterate(dest, n, c);
		}
		else
		{
			n++;
			c = restart(c);
		}
		if (c.r == (int)ft_strlen(dest[0]) - 1 && c.c == c.r - 1)
		{
			n--;
			c = iterate_delete(dest, n, c);
		}
	}
}

char			**ft_solve(char *src)
{
	int			n;
	int			m;
	int			i;
	t_spoint	c;
	char		**dest;

	c.c = 0;
	c.r = 0;
	n = 0;
	m = (ft_sqrt(tetra_num(src) * 4));
	dest = ft_map(m, m, '.');
	i = check_alpha(dest, src);
	while (i == 0)
	{
		dest = ft_map(m, m, '.');
		short_solve(dest, src, n, c);
		m++;
		i = check_alpha(dest, src);
	}
	return (dest);
}
