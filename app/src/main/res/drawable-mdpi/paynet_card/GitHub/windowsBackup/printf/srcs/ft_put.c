/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:33:37 by dbraghis          #+#    #+#             */
/*   Updated: 2017/06/30 20:52:19 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_checkox(t_format *format, unsigned long long arg)
{
	char		*str;
	char		specifier;

	str = NULL;
	specifier = format->format;
	if (specifier == 'o' || specifier == 'O')
		str = ft_itoa_base((unsigned long long)arg, "01234567");
	else if (specifier == 'x')
		str = ft_itoa_base((unsigned long long)arg, "0123456789abcdef");
	else if (specifier == 'X')
		str = ft_itoa_base((unsigned long long)arg, "0123456789ABCDEF");
	else
		str = ft_itoa_base(arg, "0123456789");
	return (str);
}

char			*ft_get_unsigned_args(t_format *format, va_list ap)
{
	unsigned long long		arg;
	t_type					type;
	char					*str;

	arg = 0;
	type = format->type;
	str = NULL;
	if (type == T_UNS_INT)
		arg = va_arg(ap, unsigned int);
	else if (type == T_UNS_LONG)
		arg = va_arg(ap, unsigned long);
	else if (type == T_UNS_LONG_LONG)
		arg = va_arg(ap, unsigned long long);
	else if (type == T_UNS_SHORT)
		arg = (unsigned short)va_arg(ap, int);
	else if (type == T_UNS_CHAR)
		arg = (unsigned char)va_arg(ap, int);
	else if (type == T_UINTMAX_T)
		arg = va_arg(ap, unsigned long long);
	else if (type == T_SIZE_T)
		arg = va_arg(ap, size_t);
	else if (type == T_SSIZE_T)
		return (ft_lltoa(va_arg(ap, ssize_t)));
	str = ft_checkox(format, arg);
	return (str);
}

char			*ft_get_signed_args(t_format *format, va_list ap)
{
	long long			arg;
	t_type				type;
	char				*str;

	arg = 0;
	type = format->type;
	str = NULL;
	if (type == T_INT)
		arg = va_arg(ap, int);
	if (type == T_LONG)
		arg = va_arg(ap, long);
	if (type == T_LONG_LONG)
		arg = va_arg(ap, long long);
	if (type == T_SHORT)
		arg = (short)va_arg(ap, int);
	if (type == T_CHAR)
		arg = (char)va_arg(ap, int);
	if (type == T_INTMAX_T)
		arg = va_arg(ap, long long);
	str = ft_lltoa(arg);
	return (str);
}

wchar_t			*ft_get_wint_arg(t_format *format, va_list ap)
{
	wchar_t		*arg;

	(void)format;
	arg = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	arg[0] = (wchar_t)va_arg(ap, wint_t);
	return (arg);
}

int				ft_arg_get(va_list ap, t_format *format)
{
	wchar_t			*arg;
	size_t			printed;
	t_type			type;

	printed = 0;
	arg = NULL;
	type = format->type;
	if (0 < type && type < 7)
		arg = (wchar_t *)ft_get_signed_args(format, ap);
	else if (7 <= type && type <= 14)
		arg = (wchar_t *)ft_get_unsigned_args(format, ap);
	else if (type == 16)
		arg = ft_get_wint_arg(format, ap);
	else if (17 <= type && type <= 20)
		arg = ft_get_ptr_arg(format, ap);
	printed = ft_proceed(format, arg);
	free(arg);
	free(format);
	return (printed);
}
