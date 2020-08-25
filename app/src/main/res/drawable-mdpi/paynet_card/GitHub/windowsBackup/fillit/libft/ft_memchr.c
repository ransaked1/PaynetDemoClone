/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:01:04 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/26 21:15:42 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *strsrc;

	strsrc = (unsigned char*)src;
	while (len > 0 && *strsrc != (unsigned char)c)
	{
		len--;
		strsrc++;
	}
	if (len == 0)
		return (NULL);
	else
		return (strsrc);
}
