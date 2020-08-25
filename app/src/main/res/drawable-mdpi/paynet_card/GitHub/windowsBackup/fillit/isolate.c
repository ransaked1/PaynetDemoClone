/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		to_zero_bottom(char *src)
{
	int		i;

	i = ft_strlen(src) - 2;
	while (!(src[i] >= 'A' && src[i] <= 'Z'))
	{
		src[i] = '\0';
		i--;
	}
}

void		to_zero_top(char *src)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = ft_strnew(30);
	while (!(src[i] >= 'A' && src[i] <= 'Z'))
		i++;
	while (src[i - 1] == '.' && i > 0)
		i--;
	while (src[i])
	{
		tab[j] = src[i];
		i++;
		j++;
	}
	ft_strcpy(src, tab);
	free(tab);
	return ;
}

char		*ft_isolate_str(char *src, int n)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = ft_strnew(30);
	while (src[i])
	{
		if (src[i] == '\n')
		{
			n--;
			i++;
		}
		if (n == 0)
		{
			tab[j] = src[i];
			j++;
		}
		i++;
	}
	return (tab);
}

char		**isolate(char *src, int n)
{
	char	*tab1;
	char	**tab2;

	turn_to_alpha(src);
	tab1 = ft_isolate_str(src, n);
	to_zero_top(tab1);
	to_zero_bottom(tab1);
	tab2 = ft_strsplit(tab1, '%');
	free(tab1);
	move_back_map_recursive(tab2);
	return (tab2);
}
