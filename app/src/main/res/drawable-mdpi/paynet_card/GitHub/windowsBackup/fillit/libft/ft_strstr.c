/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 18:51:34 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/12 11:24:01 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int pozitie;
	int lungime;

	i = 0;
	pozitie = 0;
	lungime = 0;
	while (to_find[lungime] != '\0')
		lungime++;
	if (lungime == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (to_find[pozitie] == str[i + pozitie])
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
