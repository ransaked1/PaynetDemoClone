/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:31:41 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:31:43 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t		*ft_get_ptr_arg(t_format *format, va_list ap)
{
	wchar_t		*arg;
	t_type		type;
	char		*str;

	arg = NULL;
	str = NULL;
	type = format->type;
	if (type == 17)
		arg = ft_wstrdup(va_arg(ap, wchar_t *));
	else if (type == 18)
		arg = (wchar_t *)ft_strdup(va_arg(ap, char *));
	else if (type == 19)
		arg = (wchar_t *)ft_itoa_base(va_arg(ap, unsigned long), "0123456789");
	else if (type == 20)
	{
		str = ft_strnew(1);
		str[0] = format->format;
		arg = (wchar_t *)str;
	}
	return (arg);
}
