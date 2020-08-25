/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:11:41 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/23 18:11:43 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptrdest;
	const char	*ptrsrc;

	if (n && dest != src)
	{
		ptrdest = dest;
		ptrsrc = src;
		while (n--)
			*ptrdest++ = *ptrsrc++;
	}
	return (dest);
}
