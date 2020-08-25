/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 21:16:06 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 21:16:55 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_duplicat(char **argv, t_stacks *stacks)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		tmp = argv[i];
		while (argv[j] != NULL)
		{
			if (i != j)
			{
				if (ft_strcmp(tmp, argv[j]) == 0)
					ft_exit(stacks, ERROR);
			}
			j++;
		}
		i++;
	}
}

char	**ft_parsing(char *arg, t_stacks *stacks)
{
	char	**stack;
	int		i;

	i = 0;
	stack = ft_strsplit(arg, ' ');
	while (stack[i] != NULL)
		i++;
	stacks->count = i;
	ft_duplicat(stack, stacks);
	return (stack);
}

void	free_arg(char **arg)
{
	int		i;

	i = 0;
	while (arg[i] != NULL)
	{
		arg[i] = NULL;
		i++;
	}
	free(arg);
}

void	check_arg1(t_stacks *stacks, char **arg, int i)
{
	int		tmp1;
	long	tmp;

	tmp = ft_atol(arg[i]);
	tmp1 = ft_atoi(arg[i]);
	if (tmp1 < INT_MIN || tmp > INT_MAX || tmp != tmp1)
		ft_exit(stacks, ERROR);
	ft_push_front(stacks->stack_a, tmp1);
}

void	check_arg(t_stacks *stacks, char **arg)
{
	int		i;
	int		done;

	i = 0;
	done = 1;
	if (ft_isnbr(arg[0]) == 1 && stacks->count == 1)
		ft_exit(stacks, 69);
	if (stacks->count != 1)
		ft_duplicat(arg, stacks);
	else
	{
		arg = ft_parsing(arg[i], stacks);
		done = 0;
	}
	i = ft_isflag(arg);
	while (i < stacks->count)
	{
		if (ft_isnbr(arg[i]) == 0)
			ft_exit(stacks, ERROR);
		check_arg1(stacks, arg, i);
		i++;
	}
	if (done == 0)
		free_arg(arg);
}
