/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:48:30 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:50:01 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_put(t_alist *list_a, t_alist *list_b, int *flag)
{
	if (flag[0] == 1)
	{
		ft_putstr("STACK A: ");
		ft_printlist(list_a);
		ft_putstr("STACK B: ");
		ft_printlist(list_b);
	}
}

void			ft_norm(t_alist *list1, t_elem *tmp)
{
	list1->head->prev = tmp;
	tmp->next = list1->head;
	tmp->prev = NULL;
	list1->head = tmp;
}

void			push_head(t_alist *list1, t_alist *list2)
{
	t_elem		*tmp;

	tmp = list2->head;
	if (list2->len > 1)
	{
		list2->head->next->prev = NULL;
		list2->head = list2->head->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	if (list1->head == NULL)
		list1->head = tmp;
	else
		ft_norm(list1, tmp);
	if (list1->tail == NULL)
		list1->tail = tmp;
	list2->len--;
	list1->len++;
	if (list2->len == 0)
	{
		list2->head = NULL;
		list2->tail = NULL;
	}
}

void			ft_push_front(t_alist *list, int value)
{
	t_elem		*node;

	node = (t_elem *)malloc(sizeof(t_elem));
	if (node == NULL)
		exit(ERROR);
	node->val = value;
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->tail = node;
	if (list->head == NULL)
		list->head = node;
	list->len++;
}

void			ft_printlist(t_alist *list)
{
	t_elem		*tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_putnbr(tmp->val);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
