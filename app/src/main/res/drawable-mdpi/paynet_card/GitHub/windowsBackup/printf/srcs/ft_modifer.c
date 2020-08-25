/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:34:25 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:34:27 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_type		ft_apply_j_modifier(char specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == 'd' || specifier == 'i' || specifier == 'D')
		type = T_LONG_LONG;
	else if (specifier == 'o' || specifier == 'O'
		|| specifier == 'u' || specifier == 'U'
		|| specifier == 'x' || specifier == 'X')
		type = T_UNS_LONG_LONG;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_apply_z_modifier(char specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == 'd' || specifier == 'i' || specifier == 'D')
		type = T_SSIZE_T;
	else if (specifier == 'o' || specifier == 'O'
		|| specifier == 'u' || specifier == 'U'
		|| specifier == 'x' || specifier == 'X')
		type = T_SIZE_T;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_set_type(char specifier)
{
	if (specifier == 's')
		return (T_CHAR_PTR);
	else if (specifier == 'S')
		return (T_WCHAR_T_PTR);
	else if (specifier == 'p')
		return (T_VOID_PTR);
	else if (specifier == 'd' || specifier == 'i')
		return (T_INT);
	else if (specifier == 'D')
		return (T_LONG);
	else if (to_find("ouxX", specifier))
		return (T_UNS_INT);
	else if (specifier == 'O' || specifier == 'U')
		return (T_UNS_LONG);
	else if (specifier == 'c')
		return (T_CHAR);
	else if (specifier == 'C')
		return (T_WCHAR_T);
	else
		return (T_NOT_VALID_TYPE);
	return (0);
}

t_format	*ft_apply_modifier(t_format *format, int modifier)
{
	char		specifier;

	specifier = format->format;
	if (modifier == 0 || specifier == 'C' || specifier == 'S')
		format->type = ft_set_type(specifier);
	else if (modifier == 6)
		format->type = ft_apply_l_modifier(specifier);
	else if (modifier == 10)
		format->type = ft_apply_ll_modifier(specifier);
	else if (modifier == 5)
		format->type = ft_apply_h_modifier(specifier);
	else if (modifier == 11)
		format->type = ft_apply_hh_modifier(specifier);
	else if (modifier == 7)
		format->type = ft_apply_j_modifier(specifier);
	else if (modifier == 8)
		format->type = ft_apply_z_modifier(specifier);
	return (format);
}
