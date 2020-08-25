/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:01:04 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/26 21:15:42 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_digits(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_fillstring(char *str, int n, int x, int s)
{
	while (x >= 0)
	{
		if (n < 0)
			n = -n;
		str[x] = n % 10 + '0';
		n = n / 10;
		if (x == 0 && s == 1)
			str[x] = '-';
		x--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char*str;
	int x;
	int s;

	s = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		s = 1;
	x = ft_digits(n) - 1;
	str = ft_memalloc(ft_digits(n) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_fillstring(str, n, x, s));
}
