/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:55:14 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/08 18:13:09 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t i;
	size_t pozitie;
	size_t lungime;

	i = 0;
	pozitie = 0;
	lungime = ft_strlen(to_find);
	if (lungime == 0)
		return (str);
	while (str[i] != '\0' && i < n)
	{
		while (to_find[pozitie] == str[i + pozitie] && (i + pozitie < n))
		{
			if (pozitie == lungime - 1)
				return (str + i);
			pozitie++;
		}
		pozitie = 0;
		i++;
	}
	return (0);
}
