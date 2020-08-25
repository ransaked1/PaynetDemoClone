/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:33:03 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:33:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t		*ft_apply_zero_flag_wstr(int width, wchar_t *arg)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (arg[i])
		len = (arg[i++] == ' ') ? len + 1 : len;
	len = (unsigned int)ft_wstrlen(arg) - len;
	i = 0;
	while (arg[i] && (int)len < (int)width)
	{
		if (arg[i] == L' ')
			arg[i] = L'0';
		else if (arg[i] && arg[i] == '-' && ft_isdigit(arg[i + 1]))
		{
			arg[i] = L'0';
			arg[0] = L'-';
		}
		i++;
	}
	return (arg);
}

wchar_t		*ft_get_spaces_wstr(int width)
{
	wchar_t	*spaces;
	int		i;

	spaces = ft_memalloc(sizeof(wchar_t) * width + 1);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	return (spaces);
}

wchar_t		*ft_apply_width_wstr(t_format *format, wchar_t *arg,
			void *orig_arg)
{
	int		width;
	int		len;
	wchar_t	*str;
	wchar_t	*spaces;

	width = format->min_width;
	len = ft_wstrlen(arg);
	str = NULL;
	spaces = NULL;
	if (width > (int)len)
	{
		spaces = ft_get_spaces_wstr(width - len);
		if (format->minus ||
			(format->type == T_VOID_PTR && format->zero))
			str = ft_wstrjoin(arg, spaces);
		else
			str = ft_wstrjoin(spaces, arg);
		if (!str)
			return (NULL);
	}
	else
		return (arg);
	if (arg != orig_arg)
		free(arg);
	return (str);
}

char		*ft_apply_sharp_flag_hexa(char specifier, int precision,
										t_format *format, char *arg)
{
	char	*str;
	int		spaces;

	str = arg;
	spaces = 0;
	while ((arg[spaces] == ' ' || arg[spaces] == '0') && arg[spaces])
		spaces++;
	if (ft_atoi(arg) == 0)
		str = ((specifier == 'x' || specifier == 'X')
				&& precision == 0) ? ft_strdup("0") : ft_strdup("0");
	else if (spaces >= 2 && precision <= 0)
	{
		spaces = (format->zero) ? spaces - spaces + 2 : spaces;
		str[spaces - 2] = '0';
		str[spaces - 1] = (specifier == 'x') ? 'x' : 'X';
	}
	else if (specifier == 'x')
		str = ft_strjoin("0x", arg);
	else
		str = ft_strjoin("0X", arg);
	return (str);
}
