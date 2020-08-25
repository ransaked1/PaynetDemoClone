/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:34:10 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:34:12 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_init_format(t_format *format)
{
	format->precision = -1;
	format->min_width = 0;
	format->modifier = 0;
	format->hashtag = 0;
	format->minus = 0;
	format->plus = 0;
	format->zero = 0;
	format->space = 0;
}

int				ft_analyze(va_list *arg, char **i)
{
	int			modifier;
	t_format	*format;
	int			rez;

	rez = 0;
	format = (t_format *)malloc(sizeof(t_format));
	if (**i == '%')
	{
		(*i)++;
		if (**i != '\0')
		{
			ft_init_format(format);
			*i = ft_arg_parse(format, *i, &modifier);
			rez = ft_arg_get(*arg, format);
		}
	}
	return (rez);
}

char			*ft_arg_parse(t_format *format, char *str, int *modifier)
{
	char	*tmp;
	char	*piece;
	int		i;

	i = 1;
	*modifier = 0;
	tmp = str;
	while ((ft_isflag(str) || ft_isdigit(*str)
		|| ft_ismodifier(str)) && !ft_isspec(str) && *str)
	{
		str++;
		i++;
	}
	piece = ft_strsub(tmp, 0, i);
	format->format = *str;
	str++;
	*modifier = ft_arg_modifier(piece);
	format->modifier = *modifier;
	ft_arg_flags(piece, format);
	ft_arg_width(piece, format);
	ft_arg_precision(piece, format);
	format = ft_check_flags(format);
	format = ft_apply_modifier(format, *modifier);
	return (str);
}
