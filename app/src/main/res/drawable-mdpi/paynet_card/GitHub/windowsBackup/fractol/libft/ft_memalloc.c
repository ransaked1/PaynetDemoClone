/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:42:42 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/04 11:13:18 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t marime)
{
	void *ptr;

	ptr = malloc(marime);
	if (ptr)
		ft_bzero(ptr, marime);
	return (ptr);
}
