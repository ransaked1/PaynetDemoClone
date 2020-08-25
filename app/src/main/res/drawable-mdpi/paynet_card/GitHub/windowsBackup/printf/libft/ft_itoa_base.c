/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:38:47 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:38:53 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char				*s;
	unsigned long long	i;
	char				*tmp1;
	char				*tmp2;

	i = ft_strlen(base);
	tmp1 = NULL;
	tmp2 = NULL;
	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n >= i)
	{
		free(s);
		tmp1 = ft_itoa_base(n / i, base);
		tmp2 = ft_itoa_base(n % i, base);
		s = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
	}
	else if (n < i)
	{
		s[0] = base[n];
		s[1] = '\0';
	}
	return (s);
}
