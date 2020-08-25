/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:41:30 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:43:09 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst			*ft_addtolst(t_lst *lst, int n)
{
	t_elem		*new;

	if (lst != NULL)
	{
		if ((new = (t_elem *)malloc(sizeof(t_elem))) != NULL)
		{
			new->val = n;
			new->next = NULL;
			if (lst->end == NULL)
			{
				lst->head = new;
				lst->end = new;
			}
			else
			{
				lst->end->next = new;
				lst->end = new;
			}
		}
		lst->argc++;
	}
	return (lst);
}

void			print_move(t_lst *lst)
{
	t_elem		*elem;

	elem = lst->head;
	while (elem)
	{
		ft_putnbr(elem->val);
		ft_putstr(" ");
		elem = elem->next;
	}
}

void			ft_sa(t_lst *list_a, t_lst *b)
{
	long int	tmp;

	if (list_a->head == NULL || list_a->head->next == NULL)
		return ;
	tmp = list_a->head->val;
	list_a->head->val = list_a->head->next->val;
	list_a->head->next->val = tmp;
	ft_buf("sa\n", list_a, b);
}

void			ft_sb(t_lst *list_b, t_lst *a)
{
	long int	tmp;

	if (list_b->head == NULL || list_b->head->next == NULL)
		return ;
	tmp = list_b->head->val;
	list_b->head->val = list_b->head->next->val;
	list_b->head->next->val = tmp;
	ft_buf("sb\n", a, list_b);
}

void			ft_ss(t_lst *list_a, t_lst *list_b)
{
	long int	tmp;

	if (list_a->head == NULL || list_a->head->next == NULL
		|| list_b->head == NULL || list_b->head->next == NULL)
		return ;
	tmp = list_a->head->val;
	list_a->head->val = list_a->head->next->val;
	list_a->head->next->val = tmp;
	tmp = list_b->head->val;
	list_b->head->val = list_b->head->next->val;
	list_b->head->next->val = tmp;
	ft_buf("ss\n", list_a, list_b);
}
