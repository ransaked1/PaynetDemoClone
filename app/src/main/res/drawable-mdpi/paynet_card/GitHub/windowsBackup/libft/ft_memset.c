/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:27:46 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/12 18:29:35 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *in, int data, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)in;
	i = 0;
	while (len > 0)
	{
		ptr[i] = (unsigned char)data;
		i++;
		len--;
	}
	return (in);
}
