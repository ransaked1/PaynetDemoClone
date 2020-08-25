/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:44:52 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/12 17:28:50 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char		*strsrc;

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
