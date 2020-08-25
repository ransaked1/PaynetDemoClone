/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 19:12:11 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/12 18:19:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		j;
	size_t		i;

	i = ft_strlen(dest);
	j = ft_strlen(dest);
	while ((i < ft_strlen(dest) + ft_strlen(src)) &&
			((i - j) < n) && src[i - j])
	{
		dest[i] = src[i - j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
