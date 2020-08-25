/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 21:02:26 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/13 21:36:52 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char *d;

	d = malloc(ft_strlen(src) + 1);
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, src);
	return (d);
}
