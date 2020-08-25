/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:54:19 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:51:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define ERROR -1
# define EXCEPTION -2
# define BUFF_S 10

# define GET_NEXT_LINE_H
# define MAX_FD 4864
# define BUFF_SIZE 5

typedef	struct		s_gnl
{
	struct s_gnl	*next;
	char			*buff;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

typedef struct		s_elem
{
	struct s_elem	*prev;
	struct s_elem	*next;
	long int		val;
}					t_elem;

typedef struct		s_alist
{
	struct s_elem	*head;
	struct s_elem	*tail;
	int				len;
	int				pos;
}					t_alist;

typedef struct		s_stacks
{
	t_alist			*stack_a;
	t_alist			*stack_b;
	int				count;
}					t_stacks;

void				sa(t_alist *list_a);
void				sb(t_alist *list_a);
void				ss(t_alist *list_a, t_alist *list_b);
void				pa(t_alist *list_a, t_alist *list_b);
void				pb(t_alist *list_a, t_alist *list_b);
void				ra(t_alist *list);
void				rb(t_alist *list);
void				rr(t_alist *list_a, t_alist *list_b);
void				rra(t_alist *list);
void				rrb(t_alist *list);
void				rrr(t_alist *list_a, t_alist *list_b);

void				ft_exit(t_stacks *stacks, int error);
void				check_arg(t_stacks *stacks, char **argv);
void				ft_push_front(t_alist *list, int value);
int					get_next_line(const int fd, char **line);
void				push_head(t_alist *list1, t_alist *list2);
void				read_op(t_alist *list_a, t_alist *list_b, int *flag);
void				ft_printlist(t_alist *list);
void				ft_put(t_alist *list_a, t_alist *list_b, int *flag);
int					ft_isflag(char **str);
int					*ft_getflag(char **str);

#endif
