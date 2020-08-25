/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:31:27 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/11 19:40:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char				**ft_strsplit(char const *s, char c)
{
	char		**rez;
	int			n;
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	rez = (char **)malloc(ft_ncuvinte(s, c) * sizeof(*rez) + 1);
	if (rez == NULL)
		return (NULL);
	n = ft_ncuvinte(s, c);
	while (n-- > 0)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		rez[k] = ft_strsub(s, i, ft_lcuvint(s, c, i));
		if (rez[k] == NULL)
			return (NULL);
		i = i + ft_lcuvint(s, c, i);
		k++;
	}
	rez[k] = NULL;
	return (rez);
}
