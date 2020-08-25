/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:32:09 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:32:11 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t				*ft_get_zero_wstr(int len)
{
	wchar_t	*str;

	str = ft_memalloc(len * sizeof(wchar_t) + 1);
	if (!str)
		return (NULL);
	while (len)
		str[--len] = '0';
	return (str);
}

char				*ft_apply_precision_ptr(t_format *format,
		char *arg, unsigned long fatoi)
{
	char	*str;

	str = NULL;
	if (fatoi == 0)
	{
		if (format->precision == 0)
			return (ft_strdup("0x"));
		else if (format->precision > 0)
			str = ft_get_zero(format->precision);
	}
	else
	{
		arg = ft_itoa_base(fatoi, "0123456789abcdef");
		if ((int)ft_strlen(arg) < format->precision)
			str = ft_strjoin(ft_get_zero(format->precision - \
								ft_strlen(arg)), arg);
		else
			str = ft_strdup(arg);
	}
	return (ft_strjoin("0x", str));
}

unsigned long		ft_ultoi(const char *str)
{
	unsigned long		n;
	unsigned int		i;

	n = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
}

int					ft_proceed_ptr(t_format *format, char *arg)
{
	int				n;
	unsigned long	fatoi;
	char			*to_print;
	char			*tmp;

	n = 0;
	fatoi = ft_ultoi(arg);
	to_print = arg;
	tmp = NULL;
	if (format->precision >= 0)
		to_print = ft_apply_precision_ptr(format, to_print, fatoi);
	else
	{
		tmp = ft_itoa_base(fatoi, "0123456789abcdef");
		to_print = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (format->min_width > 0)
		to_print = ft_apply_width(format, to_print, arg);
	to_print = (char *)ft_apply_flags(format, (wchar_t *)to_print, to_print);
	ft_putstr(to_print);
	n = ft_strlen(to_print);
	return (n);
}

int					ft_proceed_not_valid_type(t_format *format, char *arg)
{
	int		n;
	char	*to_print;

	n = 0;
	to_print = arg;
	if (format->min_width > 0)
		to_print = ft_apply_width(format, to_print, arg);
	to_print = (char *)ft_apply_flags(format, (wchar_t *)to_print, arg);
	ft_putstr(to_print);
	n = ft_strlen(to_print);
	return (n);
}
