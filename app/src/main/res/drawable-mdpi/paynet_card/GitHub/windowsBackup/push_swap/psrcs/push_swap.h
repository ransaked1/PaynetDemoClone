/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:38:59 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/06 20:47:15 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

char					g_buf[4096];
int						g_i;

typedef struct			s_elem
{
	int					val;
	struct s_elem		*next;
	struct s_elem		*prev;
}						t_elem;

typedef struct			s_lst
{
	size_t				argc;
	size_t				c;
	int					len;
	struct s_elem		*head;
	struct s_elem		*end;
}						t_lst;

t_lst					*ft_addtolst(t_lst *lst, int n);
void					print_move(t_lst *lst);
t_lst					*ft_newlst(void);
void					ft_dcheck(t_lst *lst, long value);

void					ft_bufset(void);
void					ft_display();
void					ft_buf(char *str, t_lst *a, t_lst *b);

void					ft_sa(t_lst *list_a, t_lst *b);
void					ft_sb(t_lst *list_b, t_lst *a);
void					ft_ss(t_lst *list_a, t_lst *list_b);

void					ft_rra(t_lst *list, t_lst *b);
void					ft_rrb(t_lst *list, t_lst *a);
void					ft_rrr(t_lst *list_a, t_lst *list_b);

void					ft_ra(t_lst *list_a, t_lst *b);
void					ft_rb(t_lst *list_b, t_lst *a);
void					ft_rr(t_lst *list_a, t_lst *list_b);

void					ft_push_a(t_lst *a, t_lst *b);
void					ft_push_b(t_lst *a, t_lst *b);

void					ft_algoritm(t_lst *a, t_lst *b, t_elem *elem);
int						ft_first_check(t_lst *a, t_lst *b, t_elem *back,
		t_elem *front);
int						ft_final_check(t_lst *a, t_lst *b);
int						ft_sorted_check(t_elem *back, t_elem *front);
t_lst					*ft_init_a1(int a, char **gv, t_lst	*list);
t_lst					*ft_init_a(int a, char **gv, t_lst	*list);

#endif
