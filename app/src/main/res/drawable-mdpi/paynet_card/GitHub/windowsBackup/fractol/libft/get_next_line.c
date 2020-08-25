/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcojocar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:54:20 by mcojocar          #+#    #+#             */
/*   Updated: 2016/12/21 20:54:24 by mcojocar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <stdio.h>

void	*ft_re(char *src, size_t srcsize, size_t newsize)
{
	int		min;
	void	*ret;

	min = newsize;
	if (srcsize < newsize)
		min = srcsize;
	if (!src)
		return (NULL);
	ret = ft_memalloc(newsize);
	ft_memcpy(ret, src, min);
	free(src);
	return (ret);
}

int		ft_check_b_read(int b_read, char **line, char *str)
{
	if (b_read < 0)
		return (-1);
	if (b_read == 0 && ft_strlen(*line) == 0 && (!str || ft_strlen(str) == 0))
		return (0);
	return (1);
}

int		ft_read(const int fd, char **l, char **str)
{
	int		b_read;
	char	buff[BUFF_SIZE + 1];
	char	*ptr;

	while ((b_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[b_read] = '\0';
		if ((ptr = ft_strchr(buff, '\n')) != NULL)
			break ;
		*l = ft_re(*l, ft_strlen(*l), ft_strlen(*l) + ft_strlen(buff));
		ft_strcat(*l, buff);
		ft_strclr(buff);
	}
	if (b_read <= 0)
		return (ft_check_b_read(b_read, l, str[fd]));
	if (buff[0] != '\n')
	{
		*ptr = '\0';
		*l = ft_re(*l, ft_strlen(*l), ft_strlen(*l) + ft_strlen(buff));
		ft_strcat(*l, buff);
	}
	str[fd] = ft_strdup(++ptr);
	return (ft_check_b_read(b_read, l, str[fd]));
}

int		get_next_line(const int fd, char **line)
{
	char		*ptr;
	int			result;
	static char	*str[MAX_FD];

	if (!(fd >= 0 && fd < MAX_FD) || !line || read(fd, str[fd], 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (str[fd] != NULL)
	{
		if ((ptr = ft_strchr(str[fd], '\n')) != NULL)
		{
			*ptr = '\0';
			*line = ft_re(*line, ft_strlen(*line),
				ft_strlen(*line) + ft_strlen(str[fd]));
			ft_strcat(*line, str[fd]);
			str[fd] = ++ptr;
			return (1);
		}
		*line = ft_re(*line, ft_strlen(*line),
			ft_strlen(*line) + ft_strlen(str[fd]));
		ft_strcat(*line, str[fd]);
		ft_bzero(str[fd], ft_strlen(str[fd]));
	}
	result = ft_read(fd, line, str);
	return (result);
}
