/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:34:33 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:34:35 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putwchar(wint_t x)
{
	size_t	j;
	char	c[4];
	wint_t	tmp;

	j = 1;
	if (x <= 0x7F)
		return (write(1, &x, 1));
	if (x > 0x1FFFFF)
		return (-1);
	while (1)
	{
		tmp = 63u & x;
		if (!(x >>= 6))
			break ;
		c[4 - j++] = 128u | tmp;
	}
	c[4 - j] = (-128 >> (j - 1)) | tmp;
	return (write(1, &(c[4 - j]), j));
}

int		ft_putwstr(wchar_t *str)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		result += ft_putwchar(str[i]);
		i++;
	}
	return (result);
}

int		ft_isflag(char *str)
{
	if (*str == '-')
		return (1);
	else if (*str == '+')
		return (1);
	else if (*str == '#')
		return (1);
	else if (*str == ' ')
		return (1);
	else if (*str == '0')
		return (1);
	return (0);
}

int		ft_ismodifier(char *str)
{
	if (*str == 'l')
		return (1);
	else if (*str == 'h')
		return (1);
	else if (*str == 'j')
		return (1);
	else if (*str == 'z')
		return (1);
	else if (*str == '.')
		return (1);
	return (0);
}

int		ft_isspec(char *str)
{
	if (*str == 's' && *str == 'S' && *str == 'p' && *str == 'd'
		&& *str == 'D' && *str == 'i' && *str == 'o' && *str == 'O'
		&& *str == 'u' && *str == 'U' && *str == 'x' && *str == 'X'
		&& *str == 'c' && *str == 'C')
		return (1);
	return (0);
}
