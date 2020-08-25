/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		initialize_tab(char **tab, int rinduri, int coloane, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < rinduri)
	{
		while (j < coloane)
		{
			tab[i][j] = c;
			j++;
		}
		j = 0;
		i++;
	}
}

char		**ft_map(int rinduri, int coloane, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char*) * (rinduri + 1));
	if (tab == NULL)
		return (NULL);
	if (tab)
	{
		while (i <= rinduri)
		{
			tab[i] = (char*)malloc(sizeof(char*) * (coloane + 1));
			ft_strclr(tab[i]);
			i++;
		}
	}
	tab[i - 1] = 0;
	initialize_tab(tab, rinduri, coloane, c);
	return (tab);
}
