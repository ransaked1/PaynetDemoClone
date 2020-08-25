/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:32:44 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:32:47 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_proceed_int_args(t_format *format, wchar_t *arg)
{
	int			n;
	char		specifier;
	int			modifier;
	t_type		type;

	n = 0;
	specifier = format->format;
	modifier = format->modifier;
	type = format->type;
	if (T_INT <= type && type <= T_SSIZE_T && type != T_CHAR)
		n = ft_proceed_int(format, (char *)arg);
	else if (type == T_CHAR && specifier == 'c')
		n = ft_proceed_char(format, (char *)arg);
	else if ((type == T_CHAR || type == T_UNS_CHAR) && modifier == 11)
		n = ft_proceed_int(format, (char *)arg);
	return (n);
}

int		ft_proceed_wide_args(t_format *format, wchar_t *arg)
{
	int			n;
	t_type		type;

	type = format->type;
	n = 0;
	if (type == T_WCHAR_T)
		n = ft_proceed_wchar(format, arg);
	else if (type == T_WCHAR_T_PTR)
		n = ft_proceed_wstr(format, arg);
	return (n);
}

int		ft_proceed_ptr_args(t_format *format, wchar_t *arg)
{
	int			n;
	t_type		type;

	type = format->type;
	n = 0;
	if (type == T_CHAR_PTR)
		n = ft_proceed_str(format, (char *)arg);
	else if (type == T_VOID_PTR)
		n = ft_proceed_ptr(format, (char *)arg);
	else if (type == T_NOT_VALID_TYPE)
		n = ft_proceed_not_valid_type(format, (char *)arg);
	return (n);
}

int		ft_proceed(t_format *format, wchar_t *arg)
{
	int			nr;
	t_type		type;

	nr = 0;
	type = format->type;
	if (T_INT <= type && type <= T_SSIZE_T)
		nr = ft_proceed_int_args(format, arg);
	else if (T_WINT_T <= type && type <= T_WCHAR_T_PTR)
		nr = ft_proceed_wide_args(format, arg);
	else if (T_CHAR_PTR <= type && type <= T_NOT_VALID_TYPE)
		nr = ft_proceed_ptr_args(format, arg);
	return (nr);
}
