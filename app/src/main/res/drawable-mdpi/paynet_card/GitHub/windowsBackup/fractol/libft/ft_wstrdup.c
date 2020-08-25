/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:31:07 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:31:09 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrdup(wchar_t const *s1)
{
	int		x;
	wchar_t	*s2;

	x = 0;
	if (!s1)
		return (NULL);
	while (s1[x])
		x++;
	s2 = (wchar_t *)ft_memalloc((sizeof(wchar_t) * (x + 1)));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, sizeof(wchar_t) * x);
	return (s2);
}
