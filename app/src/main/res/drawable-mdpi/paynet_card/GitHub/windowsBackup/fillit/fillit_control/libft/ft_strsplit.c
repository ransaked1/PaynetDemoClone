/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 21:57:22 by cciobanu          #+#    #+#             */
/*   Updated: 2016/10/22 14:40:59 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char *str, char c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
		words++;
	}
	return (words);
}

static size_t	ft_stop(char *str, int start, char c)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[start] && str[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	j;
	int		words;
	int		i;
	char	*str;

	str = (char*)s;
	if (!str)
		return (NULL);
	words = ft_words(str, c);
	i = 0;
	split = (char**)ft_memalloc(sizeof(char*) * (words + 1));
	j = 0;
	while (i < words)
	{
		while ((str[j] == c) && str[j])
			j++;
		split[i] = ft_strsub(str, j, ft_stop(str, j, c));
		while ((str[j] != c) && str[j])
			j++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
