/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:25:36 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:25:38 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

int			ft_intlen(long long n)
{
	unsigned int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_lltoa(long long n)
{
	char		*s;
	int			l;
	long long	nb;
	int			k;

	k = 0;
	l = ft_intlen(n);
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	s = (char *)malloc(sizeof(*s) * (l + 1));
	s[l] = '\0';
	nb = n;
	if (n < 0)
	{
		s[0] = '-';
		nb = -n;
		k = 1;
	}
	while (l != k)
	{
		l--;
		s[l] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
