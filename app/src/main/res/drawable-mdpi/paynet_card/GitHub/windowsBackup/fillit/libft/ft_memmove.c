/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:01:04 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/26 21:15:42 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *s2;
	char *s1;

	s1 = (char*)dest;
	s2 = (char*)src;
	if (s1 > s2)
	{
		s1 = s1 + n - 1;
		s2 = s2 + n - 1;
		while (n > 0)
		{
			*s1-- = *s2--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*s1++ = *s2++;
			n--;
		}
	}
	return (dest);
}
