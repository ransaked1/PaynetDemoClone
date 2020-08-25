/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:33:16 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:33:18 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_arg_flags(char *str, t_format *format)
{
	int		i;

	i = 0;
	while ((str[i] == '-' || str[i] == '0' || str[i] == '+' ||
				str[i] == '#' || str[i] == ' ') && str[i])
	{
		if (str[i] == '-')
			format->minus = 1;
		else if (str[i] == '0')
			format->zero = 1;
		else if (str[i] == '+')
			format->plus = 1;
		else if (str[i] == ' ')
			format->space = 1;
		i++;
	}
	ft_arg_flags1(str, format);
	if (ft_strchr(str, '+'))
		format->plus = 1;
	return (1);
}

int				ft_arg_width(char *str, t_format *format)
{
	while (*str)
	{
		if (*str == '.')
			return (1);
		if (ft_isdigit(*str))
		{
			format->min_width = ft_atoi(str);
			if (format->min_width != 0)
				return (1);
		}
		str++;
	}
	return (0);
}

int				ft_arg_precision(char *str, t_format *format)
{
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			format->precision = ft_atoi(str);
			return (1);
		}
		str++;
	}
	return (0);
}

t_format		*ft_check_flags(t_format *format)
{
	if (format->min_width < 0)
		format->minus = 1;
	if (format->precision > 0)
		format->zero = 0;
	if (format->minus)
		format->zero = 0;
	if (format->plus)
		format->space = 0;
	if (format->space && format->precision == 0)
		format->zero = 0;
	return (format);
}

int				ft_arg_modifier(char *str)
{
	int		i;

	i = 0;
	if (ft_strstr(str, "hhl"))
		return (0);
	if (ft_strstr(str, "ll"))
		return (10);
	else if (ft_strstr(str, "hh"))
		return (11);
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] == 'h')
				return (5);
			if (str[i] == 'l')
				return (6);
			if (str[i] == 'j')
				return (7);
			if (str[i] == 'z')
				return (8);
			i++;
		}
	}
	return (0);
}
