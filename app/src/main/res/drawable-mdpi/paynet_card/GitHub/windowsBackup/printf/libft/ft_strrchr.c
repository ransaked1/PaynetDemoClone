/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:19:03 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/12 18:19:06 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;
	int		n;

	n = ft_strlen(s);
	i = NULL;
	while (n != 0 && s[n] != c)
		n--;
	if (s[n] == c)
		i = (char *)(s + n);
	return (i);
}
