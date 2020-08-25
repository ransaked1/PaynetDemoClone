/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:39:02 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:39:05 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_lst *list_a, t_lst *b)
{
	t_elem	*tmp;

	if (list_a->len > 1)
	{
		tmp = list_a->head;
		list_a->head = tmp->next;
		tmp->prev = list_a->end;
		tmp->next = NULL;
		list_a->end->next = tmp;
		list_a->end = tmp;
	}
	ft_buf("ra\n", list_a, b);
}

void	ft_rb(t_lst *list_b, t_lst *a)
{
	t_elem	*tmp;

	if (list_b->len > 1)
	{
		tmp = list_b->head;
		list_b->head = tmp->next;
		tmp->prev = list_b->end;
		tmp->next = NULL;
		list_b->end->next = tmp;
		list_b->end = tmp;
	}
	ft_buf("rb\n", a, list_b);
}

void	ft_rr(t_lst *list_a, t_lst *list_b)
{
	t_elem	*tmp;

	if (list_a->len > 1)
	{
		tmp = list_a->head;
		list_a->head = tmp->next;
		tmp->prev = list_a->end;
		tmp->next = NULL;
		list_a->end->next = tmp;
		list_a->end = tmp;
	}
	if (list_b->len > 1)
	{
		tmp = list_b->head;
		list_b->head = tmp->next;
		tmp->prev = list_b->end;
		tmp->next = NULL;
		list_b->end->next = tmp;
		list_b->end = tmp;
	}
	ft_buf("rr\n", list_a, list_b);
}
