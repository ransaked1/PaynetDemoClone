/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:34:00 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:34:02 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check(const char *format, char *i)
{
	if (ft_strcmp(format, "% ") == 0 || ft_strcmp(format, "% h") == 0
			|| ft_isvalid(i) == 0 || ft_strcmp(format, "%") == 0)
		return (0);
	return (1);
}

void	ft_printn(char *start, size_t n)
{
	size_t		slen;

	slen = ft_strlen(start);
	if (n < slen)
		slen = n;
	write(1, start, slen);
}

int		ft_startprint(const char *format, va_list *formatpointer)
{
	int		printed;
	char	*i;
	char	*start;

	i = (char *)format;
	printed = 0;
	start = (char *)format;
	if (ft_check(format, i) == 0)
		return (0);
	while (*i != '\0')
	{
		if (*i == '%')
		{
			ft_printn(start, i - start);
			printed = printed + ft_analyze(formatpointer, &i);
			start = i;
		}
		else if (*i != '\0')
		{
			printed++;
			i++;
		}
	}
	ft_printn(start, i - start);
	return (printed);
}

int		ft_printf(const char *format, ...)
{
	va_list		formatpointer;
	int			status;

	status = 0;
	va_start(formatpointer, format);
	status = ft_startprint(format, &formatpointer);
	va_end(formatpointer);
	return (status);
}
