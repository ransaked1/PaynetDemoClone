/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:01:04 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/26 21:15:42 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *strsrc;
	char *strdst;

	strsrc = (char*)src;
	strdst = (char*)dst;
	while (n > 0 && *strsrc != c)
	{
		n--;
		*strdst++ = *strsrc++;
	}
	if (n > 0)
	{
		*strdst++ = *strsrc++;
		return ((void*)strdst);
	}
	else
		return (NULL);
}
