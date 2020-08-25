/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_spoint		restart_k(t_spoint k)
{
	k.r = 0;
	k.c++;
	return (k);
}

int				short_v(char *src, char **dest, char **test, t_spoint c)
{
	int			n;
	t_spoint	k;

	k.r = 0;
	k.c = 0;
	n = 1;
	while (k.c < tetra_num(src))
	{
		while (n <= 19)
		{
			call_v3(dest, n);
			ft_put_tetra(test, src, k.c, c);
			if (compare_maps(dest, test) == 1)
				k.r++;
			n = clear_map_iterate(dest, test, n);
		}
		if (k.r == 0)
			return (0);
		n = 1;
		k = restart_k(k);
	}
	free(dest);
	free(test);
	return (1);
}

int				v_all(char *src)
{
	char		**dest;
	char		**test;
	t_spoint	c;
	int			i;

	dest = ft_map(4, 4, '.');
	test = ft_map(4, 4, '.');
	c.c = 0;
	c.r = 0;
	i = 0;
	i = short_v(src, dest, test, c);
	return (i);
}

int				k_intern(char **argv)
{
	char		*tab;
	int			i;

	i = 0;
	tab = create_array_from_file(open(argv[1], O_RDONLY));
	close(open(argv[1], O_RDONLY));
	i = v_all(tab);
	return (i);
}
