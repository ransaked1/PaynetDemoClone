/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:53:18 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 21:15:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_sort(t_alist *list)
{
	t_elem		*tmp;
	int			i;

	i = 0;
	tmp = list->head;
	while (tmp->next != NULL)
	{
		if (tmp->val < tmp->next->val)
			i++;
		tmp = tmp->next;
	}
	if (i == list->len - 1)
		return (1);
	return (0);
}

void	do_op(t_alist *list_a, t_alist *list_b, char *op, int *flag)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(list_a);
	else if (ft_strcmp(op, "sb") == 0)
		sb(list_b);
	else if (ft_strcmp(op, "ss") == 0)
		ss(list_a, list_b);
	else if (ft_strcmp(op, "pa") == 0)
		pa(list_a, list_b);
	else if (ft_strcmp(op, "pb") == 0)
		pb(list_a, list_b);
	else if (ft_strcmp(op, "ra") == 0)
		ra(list_a);
	else if (ft_strcmp(op, "rb") == 0)
		rb(list_b);
	else if (ft_strcmp(op, "rr") == 0)
		rr(list_a, list_b);
	else if (ft_strcmp(op, "rra") == 0)
		rra(list_a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(list_b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(list_a, list_b);
	ft_put(list_a, list_b, flag);
}

int		correct(char *op)
{
	if (ft_strcmp(op, "sa") != 0 && ft_strcmp(op, "sb") != 0 &&
			ft_strcmp(op, "ss") != 0 && ft_strcmp(op, "pa") != 0
			&& ft_strcmp(op, "pb") != 0 && ft_strcmp(op, "ra") != 0
			&& ft_strcmp(op, "rb") != 0 && ft_strcmp(op, "rr") != 0
			&& ft_strcmp(op, "rra") != 0 && ft_strcmp(op, "rrb") != 0
			&& ft_strcmp(op, "rrr") != 0)
		return (0);
	return (1);
}

void	read_op1(t_alist *list_a, t_alist *list_b, int i, int *flag)
{
	if (is_sort(list_a) && list_b->len == 0)
	{
		ft_putstr("OK\n");
		if (flag[1] == 1)
		{
			ft_putstr("Number of permutations: ");
			ft_putnbr(i);
			write(1, "\n", 1);
		}
	}
	else
	{
		ft_putstr("KO");
		write(1, "\n", 1);
	}
}

void	read_op(t_alist *list_a, t_alist *list_b, int *flag)
{
	char	*op;
	int		i;

	i = 0;
	op = ft_strnew(BUFF_S);
	while (get_next_line(0, &op))
	{
		if (correct(op))
			do_op(list_a, list_b, op, flag);
		else
		{
			printf("Error\n");
			free(op);
			exit(ERROR);
		}
		i++;
	}
	read_op1(list_a, list_b, i, flag);
	free(op);
}
