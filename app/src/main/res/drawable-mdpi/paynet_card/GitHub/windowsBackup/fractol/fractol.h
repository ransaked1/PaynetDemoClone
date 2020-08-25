/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:06:56 by dbraghis          #+#    #+#             */
/*   Updated: 2017/05/13 17:07:00 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# define B		0x00000000
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define WHITE	0x00FFFFFF
# define INT0(...)		int		__VA_ARGS__;
# define DOUBLE0(...)	double	__VA_ARGS__;
# define FLOAT0(...)	float	__VA_ARGS__;
# define CHAR0(...)		char	__VA_ARGS__;
# define CHAR1(...)		char*	__VA_ARGS__;
# define BPP		4
# define COL_STEP	16
# define HUE_RANGE	40
# define MT_MASK (1L<<6)
# define MT_NOT 6

typedef struct		s_col
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_col;

typedef struct		s_fract
{
	double			zoom;
	double			movex;
	double			movey;
	double			pim;
	double			pre;
	int				maxit;
	int				w;
	int				h;
	int				ch;
	int				chr;
	int				cs;
}					t_fract;

typedef	struct		s_data
{
	char			fr_type;
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_add;
	int				bpp;
	int				lsize;
	int				end;
	int				wx;
	int				wy;
	int				stx;
	int				sty;
	t_fract			f;
	int				help;
	int				ch_mode;
}					t_data;

typedef struct		s_allfr
{
	void			*mlx;
	t_data			data1;
	t_data			data2;
	t_data			data3;
}					t_allfr;

int					rnd(float nb);
float				floatabs(float x);
float				f_mod(float h);

t_col				sep_color(int col);
int					get_hue(int start, int range, int i);
int					hsvtorgb(float h, float s, float v);

void				julia(t_data data, t_fract f);
void				mandelbrot(t_data data, t_fract f);
void				burning_ship(t_data data, t_fract f);

void				draw(t_data e, int x, int y, int color);
void				print_fractol(char c, t_data data);
void				help_fractol(void);
void				get_help(t_data *e);
void				get_info(t_data *e);

int					key_hook(int k, void *data);
int					mouse_hook(int button, int x, int y, void *data);
int					motion_hook(int x, int y, t_data *e);
int					expose_hook(t_data *e);
#endif
