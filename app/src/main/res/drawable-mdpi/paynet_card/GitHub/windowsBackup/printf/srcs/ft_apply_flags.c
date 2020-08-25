/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:32:22 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:32:24 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t	*ft_apply_hashtag_flag(char specifier, int precision,
							t_format *format, char *arg)
{
	char	*str;
	int		spaces;

	str = NULL;
	spaces = 0;
	while (arg[spaces] == ' ' && arg[spaces])
		spaces++;
	if ((specifier == 'o' || specifier == 'O')
				&& arg[0] != '0')
	{
		if (spaces >= 1)
		{
			arg[spaces - 1] = '0';
			str = arg;
		}
		else
			str = ft_strjoin("0", (char *)arg);
	}
	else if (specifier == 'x' || specifier == 'X')
		str = ft_apply_sharp_flag_hexa(specifier, precision, format, arg);
	else
		str = ft_strdup(arg);
	return ((wchar_t *)str);
}

wchar_t	*ft_apply_zero_flag(int width, char *arg)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (arg[i])
		len = (arg[i++] == ' ') ? len + 1 : len;
	len = (unsigned int)ft_strlen(arg) - len;
	i = 0;
	while (arg[i] && (int)len < (int)width)
	{
		if (arg[i] == ' ')
			arg[i] = '0';
		else if (arg[i] && arg[i] == '-' && ft_isdigit(arg[i + 1]))
		{
			arg[i] = '0';
			arg[0] = '-';
		}
		i++;
	}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_space_flag(char specifier, char *arg)
{
	if (arg[0] != '-')
	{
		if (specifier == 'd' || specifier == 'i')
		{
			if (arg[0] == '0')
				arg[0] = ' ';
			else if (arg[0] != ' ')
				arg = ft_strjoin(" ", arg);
		}
	}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_plus_flag(t_format *format, char *arg)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = arg;
	while (str[i] && (!ft_isdigit(str[0])) && str[0])
	{
		if (str[i] == '-')
			break ;
		if (ft_isdigit(str[i]))
		{
			str[i - 1] = '+';
			break ;
		}
		i++;
	}
	if (*str && ft_isdigit(str[0]) && str[0])
	{
		if (str[0] == '0' && str[1] && format->zero)
			str[0] = '+';
		else
			str = ft_strjoin("+", arg);
	}
	return ((wchar_t *)str);
}

wchar_t	*ft_apply_flags(t_format *format, wchar_t *arg, void *orig_arg)
{
	wchar_t		*str;

	str = arg;
	if (format->zero && format->type == T_WCHAR_T_PTR)
		str = ft_apply_zero_flag_wstr(format->min_width, str);
	else if (format->zero)
		str = ft_apply_zero_flag(format->min_width, (char *)str);
	if (format->hashtag && to_find("oO", format->format) &&
			format->precision != -1)
		str = ft_apply_hashtag_flag(format->format, format->precision,
								format, (char *)str);
	else if (format->hashtag && to_find("oOxX", format->format) &&
			format->precision != 0)
		str = ft_apply_hashtag_flag(format->format, format->precision,
								format, (char *)str);
	if (format->space)
		str = ft_apply_space_flag(format->format, (char *)str);
	if (format->plus && ((T_INT <= format->type && format->type <= T_SHORT)
		|| format->type == T_INTMAX_T))
		str = ft_apply_plus_flag(format, (char *)str);
	(void)orig_arg;
	return (str);
}
