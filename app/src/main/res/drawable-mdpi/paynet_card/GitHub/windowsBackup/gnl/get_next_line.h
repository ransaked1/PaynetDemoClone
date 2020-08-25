/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:42:44 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/23 18:02:40 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FD 4864
# include "libft/includes/libft.h"

typedef struct	s_fd
{
	int			fd;
	char		*start;
	char		*str;
}				t_fd;

int				get_next_line(const int fd, char **line);
#endif
