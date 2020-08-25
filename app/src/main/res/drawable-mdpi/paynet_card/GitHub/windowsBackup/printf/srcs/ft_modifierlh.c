/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifierlh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:31:56 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:31:59 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_type		ft_apply_l_modifier(char specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == 'd' || specifier == 'i' || specifier == 'D')
		type = T_LONG;
	else if (specifier == 'o' || specifier == 'O'
			|| specifier == 'u' || specifier == 'U'
			|| specifier == 'x' || specifier == 'X')
		type = T_UNS_LONG;
	else if (specifier == 'c')
		type = T_WCHAR_T;
	else if (specifier == 's')
		type = T_WCHAR_T_PTR;
	else if (specifier == 'p')
		type = T_VOID_PTR;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_apply_ll_modifier(char specifier)
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

t_type		ft_apply_h_modifier(char specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == 'd' || specifier == 'i')
		type = T_SHORT;
	else if (specifier == 'D' || specifier == 'U')
		type = T_UNS_LONG;
	else if (specifier == 'o' || specifier == 'O'
		|| specifier == 'u' || specifier == 'D'
		|| specifier == 'x' || specifier == 'X')
		type = T_UNS_SHORT;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}

t_type		ft_apply_hh_modifier(char specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == 'd' || specifier == 'i')
		type = T_CHAR;
	else if (specifier == 'o' || specifier == 'u'
		|| specifier == 'x' || specifier == 'X')
		type = T_UNS_CHAR;
	else if (specifier == 'O' || specifier == 'U' || specifier == 'D')
		type = T_UNS_SHORT;
	else
		type = T_NOT_VALID_TYPE;
	return (type);
}
