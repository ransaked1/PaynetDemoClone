/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:55:14 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/08 18:13:09 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

void			ft_show_matrix(char **tab);
void			show_array(char *tab);
char			*create_array_from_file(int fd);
int				tetra_num(char *tab);
char			**ft_map(int rinduri, int coloane, char c);
void			turn_to_alpha(char *tab);
typedef	struct	s_destinatie
{
	int			rind;
	int			coloana;
}				t_point;
typedef	struct	s_coordonate
{
	int			r;
	int			c;
}				t_spoint;
void			move_back_map_recursive(char **src);
char			**isolate(char *src, int n);
void			ft_put_tetra(char **dest, char *src, int n, t_spoint c);
void			del_tetra(char **dest, int n);
char			**ft_solve(char *src);
int				check_alpha(char **dest, char *src);
int				check_nalpha(char **dest, int n);
t_spoint		find(char **dest, int n);
t_spoint		find_last_pos(char **dest, char *src);
t_spoint		to_next_row(t_spoint c);
int				ft_sqrt(int nb);
int				condition1(char **dest, int n, t_spoint c);
int				condition2(char **dest, int n, t_spoint c);
t_spoint		short_find(char **dest, int n, t_spoint c);
t_spoint		find(char **dest, int n);
t_spoint		restart(t_spoint c);
t_spoint		ft_iterate(char **dest, t_spoint c);
t_spoint		delete_iterate(char **dest, int n, t_spoint c);
t_spoint		iterate_delete(char **dest, int n, t_spoint c);
int				check_a(char **d);
void			v1(char **dest);
void			v2(char **dest);
void			v3(char **dest);
void			v4(char **dest);
void			v5(char **dest);
void			v6(char **dest);
void			v7(char **dest);
void			v8(char **dest);
void			v9(char **dest);
void			v10(char **dest);
void			v11(char **dest);
void			v12(char **dest);
void			v13(char **dest);
void			v14(char **dest);
void			v15(char **dest);
void			v16(char **dest);
void			v17(char **dest);
void			v18(char **dest);
void			v19(char **dest);
void			clear_map(char **dest);
void			call_v1(char **dest, int n);
void			call_v2(char **dest, int n);
void			call_v3(char **dest, int n);
int				compare_maps(char **dest, char **test);
int				clear_map_iterate(char **dest, char **test, int n);
t_spoint		restart_k(t_spoint k);
int				short_v(char *src, char **dest, char **test, t_spoint c);
int				v_all(char *src);
int				k_intern(char **argv);
int				ft_kek(char *btab, char *tab);
char			*create_array_from_file1(int fd);
#endif
