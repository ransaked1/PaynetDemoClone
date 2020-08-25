/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:29:37 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/17 19:29:39 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *result;

	if (!s1 || !s2 || !(result = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	ft_strcat(ft_strcat(result, s1), s2);
	return (result);
}
