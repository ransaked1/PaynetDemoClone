/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:27:23 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/17 19:27:25 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *ptr;

	if (n)
	{
		ptr = s;
		while (n--)
			if (*ptr++ == (char)c)
				return ((void *)(--ptr));
	}
	return (NULL);
}
