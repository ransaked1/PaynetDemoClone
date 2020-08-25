/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:56:44 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 16:57:03 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		col_b(t_col col1, t_col col2, int max, int i)
{
	float	dif;
	int		tcol;

	dif = ft_abs(col1.b - col2.b);
	if (col1.b < col2.b)
		tcol = col1.b + rund(dif / max * i);
	else if (col1.b > col2.b)
		tcol = col1.b - rund(dif / max * i);
	else
		return (col1.b);
	return (tcol);
}

int		col_g(t_col col1, t_col col2, int max, int i)
{
	float	dif;
	int		tcol;

	dif = ft_abs(col1.g - col2.g);
	if (col1.g < col2.g)
		tcol = col1.g + rund(dif / max * i);
	else if (col1.g > col2.g)
		tcol = col1.g - rund(dif / max * i);
	else
		return (col1.g);
	return (tcol);
}

int		col_r(t_col col1, t_col col2, int max, int i)
{
	float	dif;
	int		tcol;

	dif = ft_abs(col1.r - col2.r);
	if (col1.r < col2.r)
		tcol = col1.r + rund(dif / max * i);
	else if (col1.r > col2.r)
		tcol = col1.r - rund(dif / max * i);
	else
		return (col1.r);
	return (tcol);
}
