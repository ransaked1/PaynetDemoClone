/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:43:53 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:43:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_lst *list, t_lst *b)
{
	t_elem	*tmp;

	if (list->head != NULL || list->head != list->end)
	{
		tmp = list->head;
		while (tmp->next != list->end)
			tmp = tmp->next;
		tmp->next->next = list->head;
		list->head = tmp->next;
		tmp->next = NULL;
		list->end = tmp;
		ft_buf("rra\n", list, b);
	}
}

void	ft_rrb(t_lst *list, t_lst *a)
{
	t_elem	*tmp;

	if (list->head != NULL || list->head != list->end)
	{
		tmp = list->head;
		while (tmp->next != list->end)
			tmp = tmp->next;
		tmp->next->next = list->head;
		list->head = tmp->next;
		tmp->next = NULL;
		list->end = tmp;
		ft_buf("rrb\n", a, list);
	}
}

void	ft_rrr(t_lst *list_a, t_lst *list_b)
{
	t_elem	*tmp;

	if (list_a->head != NULL || list_a->head != list_a->end
		|| list_b->head != NULL || list_b->head != list_b->end)
	{
		tmp = list_a->head;
		while (tmp->next != list_a->end)
			tmp = tmp->next;
		tmp->next->next = list_a->head;
		list_a->head = tmp->next;
		tmp->next = NULL;
		list_a->end = tmp;
		tmp = list_b->head;
		while (tmp->next != list_b->end)
			tmp = tmp->next;
		tmp->next->next = list_b->head;
		list_b->head = tmp->next;
		tmp->next = NULL;
		list_b->end = tmp;
		ft_buf("rrr\n", list_a, list_b);
	}
}
