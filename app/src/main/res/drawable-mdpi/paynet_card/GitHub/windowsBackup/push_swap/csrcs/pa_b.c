/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 21:14:40 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 21:14:48 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		*ft_getflag(char **str)
{
	int		*flag;

	flag = (int *)malloc(sizeof(int) * 2);
	flag[0] = 0;
	flag[1] = 0;
	if (ft_strcmp(str[1], "-v") == 0 || ft_strcmp(str[2], "-v") == 0)
		flag[0] = 1;
	if (ft_strcmp(str[1], "-n") == 0 || ft_strcmp(str[2], "-n") == 0)
		flag[1] = 1;
	return (flag);
}

void	pa(t_alist *list_a, t_alist *list_b)
{
	if (list_b->len == 0)
		return ;
	push_head(list_a, list_b);
}

void	pb(t_alist *list_a, t_alist *list_b)
{
	if (list_a->len == 0)
		return ;
	push_head(list_b, list_a);
}
