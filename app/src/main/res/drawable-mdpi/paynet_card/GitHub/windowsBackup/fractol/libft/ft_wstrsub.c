/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:29:43 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:29:47 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrsub(wchar_t *str, unsigned int start, unsigned int len)
{
	size_t			i;
	wchar_t			*new;
	unsigned int	point;

	point = 0;
	new = ft_memalloc(sizeof(wchar_t) * (len + 1));
	if (new)
	{
		i = 0;
		while (point + ft_wcharlen(str[i + start]) <= len)
		{
			new[i] = str[i + start];
			point += ft_wcharlen(new[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
