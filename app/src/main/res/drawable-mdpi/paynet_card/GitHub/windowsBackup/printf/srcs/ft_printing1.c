/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:33:50 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:33:52 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_proceed_int(t_format *format, char *arg)
{
	int		n;
	char	*to_print;

	n = 0;
	to_print = arg;
	if (format->precision >= 0)
		to_print = ft_apply_precision(format, to_print);
	if (format->precision == -1 && (format->format == 'o' ||
				format->format == 'O'))
		to_print = ft_apply_precision(format, to_print);
	if (format->min_width > 0)
		to_print = ft_apply_width(format, to_print, arg);
	to_print = (char *)ft_apply_flags(format, (wchar_t *)to_print, arg);
	ft_putstr(to_print);
	n = ft_strlen(to_print);
	return (n);
}

int			ft_proceed_str(t_format *format, char *arg)
{
	int		n;
	char	*to_print;

	n = 0;
	to_print = arg;
	if (to_print == NULL)
		to_print = "(null)";
	if (format->precision >= 0)
		to_print = ft_apply_precision_str(format, to_print);
	if (format->min_width > 0)
		to_print = ft_apply_width(format, to_print, arg);
	to_print = (char *)ft_apply_flags(format, (wchar_t *)to_print, arg);
	ft_putstr(to_print);
	n = ft_strlen(to_print);
	return (n);
}

int			ft_proceed_char(t_format *format, char *arg)
{
	int		n;
	char	*to_print;

	n = 0;
	to_print = ft_strnew(1);
	to_print[0] = (unsigned char)ft_atoi(arg);
	if (format->precision >= 0)
		to_print = ft_apply_precision_str(format, to_print);
	if (format->min_width > 0)
		to_print = ft_apply_width(format, to_print, arg);
	to_print = (char *)ft_apply_flags(format, (wchar_t *)to_print, arg);
	if (ft_atoi(arg) == 0)
	{
		if (format->minus)
			ft_putchar((unsigned char)ft_atoi(arg));
		ft_putstr(to_print);
		n = ft_strlen(to_print);
		if (!format->minus)
			ft_putchar((unsigned char)ft_atoi(arg));
		n++;
		return (n);
	}
	ft_putstr(to_print);
	n = ft_strlen(to_print);
	return (n);
}

int			ft_proceed_wchar(t_format *format, wchar_t *arg)
{
	int		n;

	(void)format;
	n = ft_putwchar(arg[0]);
	return (n);
}

int			ft_proceed_wstr(t_format *format, wchar_t *arg)
{
	int		n;
	wchar_t	*to_print;

	n = 0;
	to_print = arg;
	if (to_print == NULL)
		to_print = L"(null)";
	if (format->precision >= 0)
		to_print = ft_apply_precision_wstr(format, to_print);
	if (format->min_width > 0)
		to_print = ft_apply_width_wstr(format, to_print, arg);
	to_print = ft_apply_flags(format, to_print, arg);
	n = ft_putwstr(to_print);
	return (n);
}
