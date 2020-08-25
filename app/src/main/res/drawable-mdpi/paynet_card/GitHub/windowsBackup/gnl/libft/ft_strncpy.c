/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:30:21 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/17 19:30:25 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (n && dst != src)
	{
		i = 0;
		while (src[i] && i++ < n)
			dst[i - 1] = src[i - 1];
		while (i < n)
			dst[i++] = '\0';
	}
	return (dst);
}
