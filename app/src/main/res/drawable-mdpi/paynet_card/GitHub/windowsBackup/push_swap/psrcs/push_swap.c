/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:35:52 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:41:23 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst			*ft_newlst(void)
{
	t_lst		*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (new != NULL)
	{
		new->argc = 0;
		new->c = 0;
		new->head = NULL;
		new->end = NULL;
	}
	return (new);
}

void			ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void			ft_dcheck(t_lst *lst, long value)
{
	t_elem		*element;

	if (lst)
	{
		element = lst->head;
		while (element)
		{
			if (element->val == value)
				ft_error();
			element = element->next;
		}
	}
}

void			ft_lstfree(t_lst *a)
{
	t_elem		*tmp;
	t_elem		*elem;

	tmp = a->head;
	elem = a->head->next;
	while (elem)
	{
		free(tmp);
		tmp = elem;
		elem = elem->next;
	}
	free(tmp);
	free(a);
}

int				main(int argc, char **argv)
{
	t_lst		*a;
	t_lst		*b;
	int			i;

	i = 1;
	ft_bufset();
	a = ft_newlst();
	b = ft_newlst();
	if (argc < 1 || !a || !b)
		ft_error();
	a->len = argc - 1;
	a = ft_init_a(argc, argv, a);
	ft_algoritm(a, b, a->head);
	if (g_i > 0)
		ft_display(a, b);
	ft_lstfree(a);
	free(b);
	return (0);
}
