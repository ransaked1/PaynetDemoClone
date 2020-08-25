/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:39:20 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:40:02 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_end_check(t_lst *a, t_lst *b)
{
	ft_rra(a, b);
	if (ft_sorted_check(a->head, a->head->next) == 1)
		return (1);
	ft_rra(a, b);
	ft_sa(a, b);
	ft_ra(a, b);
	ft_ra(a, b);
	if (ft_sorted_check(a->head, a->head->next) == 1)
		return (1);
	return (0);
}

int		ft_sorted_check(t_elem *back, t_elem *front)
{
	while (front != NULL)
	{
		if (back->val > front->val)
			return (0);
		back = back->next;
		front = front->next;
	}
	return (1);
}

int		ft_unsorted_check(t_elem *back, t_elem *front)
{
	while (front != NULL)
	{
		if (back->val < front->val)
			return (0);
		back = back->next;
		front = front->next;
	}
	return (1);
}

int		ft_first_check(t_lst *a, t_lst *b, t_elem *back, t_elem *front)
{
	if (a->argc > 3 && a->head->val < a->end->val && a->head->val <
		a->head->next->val && a->head->next->val > a->end->val)
	{
		if (ft_sorted_check(a->head, a->head->next) == 0)
			return (0);
	}
	while (front != NULL)
	{
		if (front == a->head->next && back->val > front->val)
		{
			ft_sa(a, b);
			if (ft_sorted_check(a->head, a->head->next) == 1)
				return (1);
		}
		if (front == a->end && back->val > front->val && a->argc > 3
			&& ft_end_check(a, b) == 1)
			return (1);
		if (back->val > front->val)
			return (0);
		back = back->next;
		front = front->next;
	}
	return (ft_sorted_check(a->head, a->end) == 0) ? 1 : 0;
}

int		ft_final_check(t_lst *a, t_lst *b)
{
	if (ft_sorted_check(a->head, a->head->next) == 1)
	{
		if (b->head != NULL && b->head->next != NULL &&
				ft_unsorted_check(b->head, b->head->next))
		{
			while (b->head != NULL)
				ft_push_a(a, b);
			if (b->head == NULL)
				return (1);
		}
		else
		{
			ft_push_a(a, b);
			return (1);
		}
	}
	return (0);
}
