/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:53:11 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 16:56:21 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

# define BUFF_SIZE 205
# define MAX_FD 1025
# define ER -1
# define W_WIDTH 1366
# define W_HEIGHT 1024

# define W	0x00FFFFFF
# define B	0x00000000
# define R	0x00FF0000
# define G	0x0000FF00
# define BL	0x000000FF
# define Y	0x00FFFF00
# define V	0x00FF00FF
# define O	0x0000FFFF

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define D 2
# define C 8
# define PLUS 24
# define MINUS 27
# define RESET 15

typedef struct		s_buff
{
	char		*bf;
	int			rf;
}					t_buff;

typedef struct		s_angle
{
	int		x;
	int		y;
	int		z;
}					t_angle;

typedef struct		s_pixel
{
	float			x;
	float			y;
	float			sy;
	float			z;
	float			dx;
	float			dy;
	float			dh;
	float			sdh;
	int				width;
	int				height;
	int				c;
	int				column;
	int				j;
}					t_pixel;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			**tab;
	int				x;
	int				y;
	int				z;
	int				global_col;
	int				argc;
	char			**argv;
	t_pixel			*ptab;
	t_pixel			start;
}					t_data;

typedef struct		s_col
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_col;

int					get_next_line(const int fd, char **line);
char				**read_tab(int argc, char **argv);
t_pixel				ft_start(char **argv, char **tab, t_pixel *ptab);
void				write_pixel(t_pixel *ptab, t_pixel p, char **tab);
int					c_atoi(char *str);
int					ft_abs(int i);
t_pixel				open_window(t_pixel *ptab, t_pixel start);
int					miny(t_pixel *ptab, t_pixel start);
void				ft_draw(t_data data, t_pixel start);
int					rund(float nb);
void				line(t_data data, t_pixel p1, t_pixel p2);
int					key_hook(int k, void *data);
char				**ft_split(char **tab, int i);
int					col_r(t_col col1, t_col col2, int max, int i);
int					col_g(t_col col1, t_col col2, int max, int i);
int					col_b(t_col col1, t_col col2, int max, int i);

#endif
