/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:42:42 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/04 09:49:58 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list *rez;
	t_list *tmp1;
	t_list *tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = f(lst);
	if ((rez = ft_lstnew(tmp2->content, tmp2->content_size)))
	{
		tmp1 = rez;
		lst = lst->next;
		while (lst)
		{
			tmp2 = f(lst);
			if (!(tmp1->next = ft_lstnew(tmp2->content, tmp2->content_size)))
				return (NULL);
			tmp1 = tmp1->next;
			lst = lst->next;
		}
	}
	return (rez);
}
