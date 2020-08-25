/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:30:04 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/17 19:30:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	if (n && dst != src)
	{
		i = 0;
		dst_len = ft_strlen(dst);
		while (i++ < n && src[i - 1])
			dst[dst_len + i - 1] = src[i - 1];
		dst[dst_len + i - 1] = '\0';
	}
	return (dst);
}
