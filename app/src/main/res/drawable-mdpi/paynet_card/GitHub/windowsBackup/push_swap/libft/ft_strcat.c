/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:08:44 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/12 17:50:14 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, const char *src)
{
	size_t		j;
	size_t		i;

	i = ft_strlen(dest);
	j = ft_strlen(dest);
	while ((i < ft_strlen(dest) + ft_strlen(src)) && src[i - j])
	{
		dest[i] = src[i - j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
