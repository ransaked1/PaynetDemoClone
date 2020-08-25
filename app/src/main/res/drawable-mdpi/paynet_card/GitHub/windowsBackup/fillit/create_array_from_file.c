/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/12/06 16:21:39 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*create_array_from_file(int fd)
{
	char	*tab;
	char	*tmp;
	char	c;
	int		i;

	i = 0;
	tab = ft_strnew(10);
	while (read(fd, &c, 1))
	{
		tmp = ft_strnew(i + 1);
		if (c == '\n')
		{
			tab[i++] = '%';
			read(fd, &c, 1);
		}
		tab[i++] = c;
		tab = ft_strjoin(tab, tmp);
	}
	return (tab);
}

char		*create_array_from_file1(int fd)
{
	char	*tab;
	char	*tmp;
	char	c;
	int		i;

	i = 0;
	tab = ft_strnew(10);
	while (read(fd, &c, 1))
	{
		tmp = ft_strnew(i + 1);
		tab[i++] = c;
		tab = ft_strjoin(tab, tmp);
	}
	return (tab);
}
