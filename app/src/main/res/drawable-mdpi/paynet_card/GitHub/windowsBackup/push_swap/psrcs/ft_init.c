/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:35:38 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:37:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*ft_init_a1(int a, char **gv, t_lst *list)
{
	int		i;
	int		n;

	i = 0;
	i++;
	while (a-- > 1)
	{
		n = ft_atoi(gv[i++]);
		ft_dcheck(list, n);
		list = ft_addtolst(list, n);
	}
	return (list);
}

t_lst		*ft_init_a(int a, char **gv, t_lst *list)
{
	char		**str;
	int			i;
	int			n;
	int			len;

	i = 0;
	list = ft_newlst();
	if (a == 2)
	{
		str = ft_strsplit(gv[1], ' ');
		len = ft_ncuvinte(gv[1], ' ') + 1;
		while (len-- > 1)
		{
			n = ft_atoi(str[i++]);
			ft_dcheck(list, n);
			list = ft_addtolst(list, n);
		}
	}
	else
		return (ft_init_a1(a, gv, list));
	return (list);
}
