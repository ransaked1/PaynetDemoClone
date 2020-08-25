/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:34:53 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:34:56 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_ismod(char str)
{
	if (str == 'l')
		return (1);
	else if (str == 'h')
		return (1);
	else if (str == 'j')
		return (1);
	else if (str == 'z')
		return (1);
	return (0);
}

int		ft_issp(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd'
			|| c == 'D' || c == 'i' || c == 'o' || c == 'O'
			|| c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'C' || c == 'Z')
		return (1);
	return (0);
}

int		ft_isvalid(char *format)
{
	int		i;
	int		k;
	int		p;
	int		n;

	i = 0;
	k = 0;
	p = 0;
	n = 0;
	while (format[i] != '\0')
	{
		if (ft_issp(format[i]))
			k = 1;
		if (ft_ismod(format[i]))
			n = 1;
		if (format[i] == '%')
			p++;
		i++;
	}
	if (k == 0 && n == 1)
		return (0);
	if ((k == 1 || p > 1) || (k == 0 && p <= 1))
		return (1);
	return (0);
}

void	ft_arg_flags1(char *str, t_format *format)
{
	int		i;

	i = 0;
	if (to_find(str, '#'))
	{
		while (str[i] != '\0')
		{
			if (str[i] == 'x' || str[i] == 'X' ||
					str[i] == 'o' || str[i] == 'O')
				format->hashtag = 1;
			i++;
		}
	}
	return ;
}

int		to_find(char *s, char c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = s;
	while (temp[i] != '\0')
	{
		if (temp[i] == c)
			return (1);
		i++;
	}
	return (0);
}
