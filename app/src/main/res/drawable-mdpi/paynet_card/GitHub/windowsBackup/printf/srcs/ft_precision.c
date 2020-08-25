/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:34:42 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:34:44 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_get_zero(int len)
{
	char	*str;

	str = ft_strnew((size_t)len);
	if (!str)
		return (NULL);
	while (len)
		str[--len] = '0';
	return (str);
}

char			*ft_prepend_zero(int precision, char *arg)
{
	char	*str;
	char	*arg_tmp;
	size_t	i;
	size_t	len_zero;
	int		is_negative;

	str = NULL;
	arg_tmp = arg;
	i = 0;
	len_zero = (size_t)precision - ft_strlen(arg);
	is_negative = arg_tmp[0] == '-' ? 1 : 0;
	str = ft_strnew(is_negative + precision);
	if (is_negative)
	{
		str[i++] = '-';
		len_zero += 2;
		arg_tmp++;
	}
	while (i < len_zero)
		str[i++] = '0';
	while (*arg_tmp)
		str[i++] = *(arg_tmp++);
	free(arg);
	return (str);
}

char			*ft_apply_precision(t_format *format, char *arg)
{
	char	*str;
	char	*tmp;
	size_t	len;

	str = ft_strdup(arg);
	tmp = str;
	len = (arg[0] == '-') ? ft_strlen(arg) - 1 : ft_strlen(arg);
	if ((int)len < format->precision)
		str = ft_prepend_zero(format->precision, str);
	else if (format->precision == 0 && ft_atoi(arg) == 0)
	{
		str = ft_strdup("");
		free(tmp);
	}
	return (str);
}

char			*ft_apply_precision_str(t_format *format, char *arg)
{
	char	*str;

	str = NULL;
	if (!arg)
		str = ft_get_zero(format->precision);
	else
	{
		if (ft_strlen(ft_strtrim((char *)arg)) > (size_t)format->precision)
			str = ft_strsub(arg, 0, (size_t)format->precision);
		else
			str = ft_strdup(arg);
	}
	return (str);
}

wchar_t			*ft_apply_precision_wstr(t_format *format, wchar_t *arg)
{
	wchar_t	*str;

	str = NULL;
	if (!arg)
		str = ft_get_zero_wstr(format->precision);
	else
	{
		if (ft_wstrlen(arg) > format->precision)
			str = ft_wstrsub(arg, 0, format->precision);
		else
			str = ft_wstrdup(arg);
	}
	return (str);
}
