/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:42:28 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/23 18:02:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

static t_list	*create_node(int fd)
{
	t_list	*ret;
	t_fd	*fd_node;

	fd_node = (t_fd *)malloc(sizeof(t_fd));
	fd_node->fd = fd;
	fd_node->str = ft_strnew(BUFF_SIZE);
	fd_node->start = fd_node->str;
	ret = ft_lstnew(fd_node, sizeof(t_fd));
	return (ret);
}

static t_fd		*get_node(int fd, t_list **fd_list)
{
	t_list	*tmp;
	t_fd	*fd_node;

	if (!fd_list || !*fd_list)
		*fd_list = create_node(fd);
	tmp = *fd_list;
	while (tmp)
	{
		fd_node = (t_fd *)tmp->content;
		if (fd_node->fd == fd)
			return (fd_node);
		tmp = tmp->next;
	}
	ft_lstadd(fd_list, create_node(fd));
	return ((t_fd*)(*fd_list)->content);
}

static void		handle_node(t_fd *fd_node, char **ret, char **end)
{
	long	n_nl;
	char	*nl;

	nl = ft_strchr(fd_node->str, '\n');
	if (nl)
	{
		n_nl = (long)(nl - fd_node->str);
		*end = (char *)1;
		fd_node->str[n_nl] = 0;
		*ret = ft_strdup(fd_node->str);
		fd_node->str += n_nl + 1;
	}
	else
	{
		*ret = ft_strdup(fd_node->str);
		ft_strclr(fd_node->start);
		fd_node->str = fd_node->start;
	}
}

static char		*handle_data(int count, char **ret,
					char *buff, t_fd *fd_node)
{
	long	n_nl;
	char	*nl;
	int		len;

	len = ft_strlen(*ret);
	nl = ft_strchr(buff, '\n');
	if (!nl)
	{
		*ret = ft_realloc((void *)*ret, len, len + count + 1);
		ft_strncat(*ret, buff, count);
		ft_strclr(buff);
	}
	else
	{
		n_nl = (long)(nl - buff);
		*ret = (char *)ft_realloc((void *)*ret, len, len + n_nl + 1);
		ft_strncat(*ret, buff, n_nl);
		ft_strncpy(fd_node->start, buff + n_nl + 1, BUFF_SIZE - n_nl - 1);
	}
	return (ft_strchr(buff, '\n'));
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_lsit;
	t_fd			*fd_node;
	char			*ret;
	char			*tmp[2];
	int				count;

	if (!line)
		return (-1);
	fd_node = get_node(fd, &fd_lsit);
	tmp[1] = 0;
	handle_node(fd_node, &ret, &tmp[1]);
	if (!tmp[1])
		tmp[0] = ft_strnew(BUFF_SIZE);
	else
		return ((*line = ret) ? 1 : 0);
	while (!tmp[1] && (count = read(fd, tmp[0], BUFF_SIZE)) > 0)
		tmp[1] = handle_data(count, &ret, tmp[0], fd_node);
	if (tmp[1] > tmp[0])
		ft_strcpy(fd_node->start, tmp[1] + 1);
	*line = ret;
	ft_strdel(&tmp[0]);
	if (tmp[1] || ret[0] || count)
		return ((count >= 0 ? 1 : -1));
	return (0);
}
