/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:26:16 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/12 18:25:08 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
