/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/12/06 16:00:11 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*read_tab(int argc, char **argv)
{
	int		fd;
	char	*tab;

	fd = 0;
	argc = 2;
	argc++;
	argc--;
	fd = open(argv[1], O_RDONLY);
	tab = create_array_from_file(fd);
	close(fd);
	return (tab);
}

char		*read_tab1(int argc, char **argv)
{
	int		fd;
	char	*tab;

	fd = 0;
	argc = 2;
	argc++;
	argc--;
	fd = open(argv[1], O_RDONLY);
	tab = create_array_from_file1(fd);
	close(fd);
	return (tab);
}

int			ft_proverka(int argc, char **argv)
{
	if (ft_kek(read_tab1(argc, argv), read_tab(argc, argv)) == 1)
	{
		if (k_intern(argv) == 1)
			return (1);
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	char	*tab;
	char	**tab1;

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
	if (ft_proverka(argc, argv) == 1)
	{
		tab = read_tab(argc, argv);
		tab1 = ft_solve(tab);
		ft_show_matrix(tab1);
	}
	else
		return (0);
	return (0);
}
