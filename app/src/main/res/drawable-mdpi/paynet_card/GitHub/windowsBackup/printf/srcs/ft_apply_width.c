/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:32:32 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:32:34 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_get_spaces(int width)
{
	char	*spaces;
	int		i;

	spaces = ft_strnew(width);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	return (spaces);
}

size_t		ft_get_lenwidth(t_format *format, char *arg)
{
	char	specifier;
	int		len;

	specifier = format->format;
	len = (format->type == T_CHAR) ? 1 : ft_strlen(arg);
	if (format->hashtag && format->minus && (specifier == 'o'
		|| specifier == 'O'))
		len++;
	else if (format->hashtag && format->minus && (specifier == 'x'
		|| specifier == 'X'))
		len += 2;
	else if (format->plus && arg[0] != '-' && format->minus
			&& (T_INT <= format->type && format->type <= T_SSIZE_T))
		len++;
	return (len);
}

char		*ft_apply_width(t_format *format, char *arg, void *orig_arg)
{
	size_t	len;
	char	*str;
	char	*spaces;

	len = ft_get_lenwidth(format, arg);
	str = arg;
	spaces = NULL;
	if (!str)
		return (NULL);
	if (format->min_width > (int)len)
	{
		spaces = ft_get_spaces(format->min_width - len);
		if (format->minus ||
			(format->type == T_VOID_PTR && format->zero && orig_arg != NULL))
			str = ft_strjoin(arg, spaces);
		else
			str = ft_strjoin(spaces, arg);
	}
	if (arg != orig_arg && orig_arg != NULL)
		free(arg);
	free(spaces);
	return (str);
}
