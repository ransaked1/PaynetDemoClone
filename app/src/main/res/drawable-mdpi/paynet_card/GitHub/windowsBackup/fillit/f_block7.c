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

void			call_v1(char **dest, int n)
{
	if (n == 1)
		v1(dest);
	else if (n == 2)
		v2(dest);
	else if (n == 3)
		v3(dest);
	else if (n == 4)
		v4(dest);
	else if (n == 5)
		v5(dest);
	else if (n == 6)
		v6(dest);
	else if (n == 7)
		v7(dest);
	else if (n == 8)
		v8(dest);
	else if (n == 9)
		v9(dest);
	else if (n == 10)
		v10(dest);
	else if (n == 11)
		v11(dest);
}

void			call_v2(char **dest, int n)
{
	if (n == 12)
		v12(dest);
	else if (n == 13)
		v13(dest);
	else if (n == 14)
		v14(dest);
	else if (n == 15)
		v15(dest);
	else if (n == 16)
		v16(dest);
	else if (n == 17)
		v17(dest);
	else if (n == 18)
		v18(dest);
	else if (n == 19)
		v19(dest);
}

void			call_v3(char **dest, int n)
{
	if (n >= 1 && n <= 11)
		call_v1(dest, n);
	else if (n >= 12 && n <= 19)
		call_v2(dest, n);
}

int				compare_maps(char **dest, char **test)
{
	t_spoint	d;
	int			i;

	i = 1;
	d.r = 0;
	d.c = 0;
	while (test[d.r])
	{
		while (test[d.r][d.c])
		{
			if ((test[d.r][d.c] != '.' && dest[d.r][d.c] == '.') ||
					(dest[d.r][d.c] != '.' && test[d.r][d.c] == '.'))
				return (0);
			d.c++;
		}
		d.c = 0;
		d.r++;
	}
	return (i);
}

int				clear_map_iterate(char **dest, char **test, int n)
{
	clear_map(dest);
	clear_map(test);
	n++;
	return (n);
}
