/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 22:19:20 by cciobanu          #+#    #+#             */
/*   Updated: 2016/10/22 15:24:11 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(int n)
{
	size_t			i;
	unsigned int	nbr;

	i = 0;
	if (n < 0)
	{
		i++;
		nbr = (unsigned int)-n;
	}
	else
		nbr = (unsigned int)n;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char		*ft_str_itoa(int n, char *str, size_t len)
{
	unsigned int	nbr;
	char			*s;

	s = str;
	nbr = 0;
	if (n < 0)
	{
		nbr = (unsigned int)-n;
		s[0] = '-';
	}
	else
		nbr = (unsigned int)n;
	while (nbr > 0)
	{
		len--;
		s[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = nbr_len(n);
	if (n == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = '0';
	}
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		str = ft_str_itoa(n, str, len);
	}
	return (str);
}
