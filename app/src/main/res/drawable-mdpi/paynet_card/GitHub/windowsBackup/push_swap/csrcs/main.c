/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:53:48 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 21:02:49 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				ft_isflag(char **str)
{
	if ((ft_strcmp(str[0], "-v") == 0 || ft_strcmp(str[0], "-n") == 0) &&
		(ft_strcmp(str[1], "-v") == 0 || ft_strcmp(str[1], "-n") == 0))
		return (2);
	if (ft_strcmp(str[0], "-v") == 0 || ft_strcmp(str[0], "-n") == 0)
		return (1);
	return (0);
}

void			del_list(t_alist *list)
{
	t_elem	*tmp;

	while (list->head)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
}

t_alist			*create(void)
{
	t_alist *tmp;

	tmp = (t_alist *)malloc(sizeof(t_alist));
	tmp->len = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void			ft_exit(t_stacks *stacks, int error)
{
	if (error == ERROR && stacks->stack_a != NULL && stacks->stack_b != NULL)
	{
		del_list(stacks->stack_a);
		del_list(stacks->stack_b);
	}
	if (error == EXCEPTION)
		exit(0);
	if (error == 69)
	{
		ft_putstr("OK\n");
		exit(0);
	}
	ft_putstr("Error\n");
	exit(0);
}

int				main(int argc, char **argv)
{
	t_stacks	stacks;
	t_alist		*list_a;
	t_alist		*list_b;
	int			*flag;

	flag = NULL;
	list_a = create();
	list_b = create();
	ft_bzero(&stacks, sizeof(stacks));
	if (argc >= 2)
	{
		stacks.stack_a = list_a;
		stacks.stack_b = list_b;
		stacks.count = argc - 1;
		check_arg(&stacks, &argv[1]);
		if (argc != 2)
			flag = ft_getflag(argv);
		read_op(list_a, list_b, flag);
	}
	else
		ft_exit(&stacks, EXCEPTION);
	del_list(list_a);
	free(list_a);
	free(list_b);
	return (0);
}
