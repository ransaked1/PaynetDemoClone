/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:42:28 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/11 19:58:04 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strtrim(char const *s)
{
	int			i;
	int			len;
	char		*rez;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_stringlen(s);
	rez = (char *)malloc(sizeof(rez) * len + 1);
	if (rez == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	s += i;
	i = 0;
	while (i < len)
	{
		rez[i] = *s++;
		i++;
	}
	rez[i] = '\0';
	return (rez);
}
