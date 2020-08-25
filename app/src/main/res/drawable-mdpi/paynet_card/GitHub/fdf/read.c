/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:02:42 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 17:03:24 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**array_from_file(int fd)
{
	char	**tab;
	char	*line;
	int		i;

	i = 0;
	tab = (char**)malloc(sizeof(tab) * 520);
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_strdup(line);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char		**read_tab(int argc, char **argv)
{
	int		fd;
	char	**tab;

	fd = 0;
	argc = 2;
	fd = open(argv[1], O_RDONLY);
	tab = array_from_file(fd);
	close(fd);
	return (tab);
}
