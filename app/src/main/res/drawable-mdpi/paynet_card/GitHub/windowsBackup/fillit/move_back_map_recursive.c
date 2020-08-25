/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_map_recursive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:59:32 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/27 12:53:54 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*move_back(char *src)
{
	int i;

	i = ft_strlen(src);
	src = ft_strsub(src, 1, i);
	return (src);
}

void	move_back_map(char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		src[i] = move_back(src[i]);
		i++;
	}
	return ;
}

void	move_back_map_recursive(char **src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i][0] >= 'A' && src[i][0] <= 'Z')
			j = 3;
		i++;
	}
	if (j == 3)
		return ;
	else
	{
		move_back_map(src);
		move_back_map_recursive(src);
	}
}
