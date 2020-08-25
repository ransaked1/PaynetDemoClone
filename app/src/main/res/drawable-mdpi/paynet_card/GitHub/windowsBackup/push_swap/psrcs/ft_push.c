/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:44:25 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:44:32 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_lst *a, t_lst *b)
{
	t_elem	*elem;

	if (b->head != NULL)
	{
		elem = b->head;
		if (a->head == NULL)
		{
			b->head = elem->next;
			elem->next = NULL;
			a->head = elem;
			a->end = elem;
		}
		else
		{
			b->head = elem->next;
			elem->next = a->head;
			a->head = elem;
		}
		ft_buf("pa\n", a, b);
	}
}

void	ft_push_b(t_lst *a, t_lst *b)
{
	t_elem	*elem;

	if (a->head != NULL)
	{
		elem = a->head;
		if (b->head == NULL)
		{
			a->head = elem->next;
			elem->next = NULL;
			b->head = elem;
			b->end = elem;
		}
		else
		{
			a->head = elem->next;
			elem->next = b->head;
			b->head = elem;
		}
		ft_buf("pb\n", a, b);
	}
}
