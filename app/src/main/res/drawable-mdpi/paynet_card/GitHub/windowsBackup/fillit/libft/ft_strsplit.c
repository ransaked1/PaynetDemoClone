/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbreahna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:55:14 by rbreahna          #+#    #+#             */
/*   Updated: 2016/07/08 18:13:09 by rbreahna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		words(char const *s, char c)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	if (s[0] != c)
		j++;
	if (s[i - 1] == c)
		j--;
	if (!s[0])
		return (0);
	return (j);
}

static	size_t		find_word_len(char const *s, char c, size_t order)
{
	size_t			j;
	size_t			k;

	k = 0;
	j = 0;
	if (s[0] == c)
		order++;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != c)
			order--;
		if (s[j] != c && order == 0)
		{
			while (s[j] != c && s[j++])
			{
				k++;
			}
			break ;
		}
		j++;
	}
	return (k);
}

static	char		find_char(char const *s, char c, size_t i, size_t j)
{
	char			a;
	size_t			k;
	size_t			x;

	x = 0;
	k = 0;
	if (s[0] != c && i == 0)
	{
		a = s[j];
		return (a);
	}
	if (s[0] != c)
		x++;
	while (s[k])
	{
		if (x == i)
		{
			a = s[k + j + 1];
		}
		if (s[k] == c && s[k + 1] != c)
			x++;
		k++;
	}
	return (a);
}

static	void		write_tab(char const *s, char c, char **tab)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i <= words(s, c))
	{
		while (j < find_word_len(s, c, i))
		{
			tab[i][j] = find_char(s, c, i, j);
			j++;
		}
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	return ;
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			i;
	char			**tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char*) * (words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	if (tab)
	{
		while (i <= words(s, c))
		{
			tab[i] = (char*)malloc(sizeof(char*) * (find_word_len(s, c, i)));
			i++;
		}
	}
	write_tab(s, c, tab);
	tab[i - 1] = 0;
	return (tab);
}
