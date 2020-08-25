/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:35:17 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:54:43 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_wrotate(t_elem *elem, t_elem *max)
{
	int		len;
	int		rez;

	len = 0;
	rez = 0;
	while (elem != NULL)
	{
		if (elem == max)
			rez = len;
		len++;
		elem = elem->next;
	}
	if (len / 2 < rez)
		return (0);
	return (1);
}

t_elem		*ft_minval(t_elem *elem)
{
	t_elem		*min;

	min = elem;
	while (elem != NULL)
	{
		if (elem->val < min->val)
			min = elem;
		elem = elem->next;
	}
	return (min);
}

void		ft_norme(t_lst *a, t_lst *b, t_elem *elem)
{
	while (elem != NULL)
	{
		elem = elem->next;
		ft_push_a(a, b);
	}
}

void		ft_algoritm(t_lst *a, t_lst *b, t_elem *elem)
{
	t_elem		*min;

	if (ft_first_check(a, b, a->head, a->head->next) == 1)
		return ;
	while (elem != NULL)
	{
		min = ft_minval(a->head);
		while (min != a->head)
		{
			if (ft_wrotate(a->head, min) == 1)
				ft_ra(a, b);
			else
				ft_rra(a, b);
		}
		if (ft_final_check(a, b) == 1)
			return ;
		ft_push_b(a, b);
		elem = a->head;
	}
	elem = b->head;
	ft_norme(a, b, elem);
	return ;
}
