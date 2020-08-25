/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:57:08 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/06 16:57:32 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strtoupper(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int		power(int a, int n)
{
	int		power;

	power = 1;
	while (n > 0)
	{
		power *= a;
		n--;
	}
	return (power);
}

int		position(char c)
{
	int		i;
	char	*bs;

	bs = ft_strdup("0123456789ABCDEF");
	i = 0;
	while (bs[i] != c)
		i++;
	return (i);
}

int		c_atoi(char *str)
{
	int		i;
	int		nb;

	str = ft_strtoupper(str);
	if (str[0] != '0' || str[1] != 'X')
		return (-1);
	i = 2;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9')
			&& !(str[i] >= 'A' && str[i] <= 'Z'))
			return (-1);
		i++;
	}
	i = 2;
	nb = 0;
	while (str[i] != '\0')
	{
		nb += position(str[i]) * power(16, (ft_strlen(str) - i - 1));
		i++;
	}
	return (nb);
}
