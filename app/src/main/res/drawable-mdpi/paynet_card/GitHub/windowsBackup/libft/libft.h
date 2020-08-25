/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:50:43 by dbraghis          #+#    #+#             */
/*   Updated: 2016/11/17 19:02:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

char					*ft_strcat(char *test, const char *src);
char					*ft_strncat(char *test, const char *src, size_t n);
size_t					ft_strlen(const char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t marime);
void					*ft_memccpy(void *dst, const void *src,
		int c, size_t n);
void					*ft_memchr(const void *src, int c, size_t len);
int						ft_memcmp(const void *s1, const void *s2, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *in, int data, size_t len);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strdup(const char *s1);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_tolower(int c);
int						ft_toupper(int c);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_isalpha(int x);
int						ft_isdigit(int x);
int						ft_isalnum(int x);
int						ft_isascii(int x);
int						ft_isprint(int x);
char					*ft_strstr(const char *str, const char *to_find);
char					*ft_strnstr(char const *s1, char const *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putendl(char const *s);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putstr(const char *s);
void					ft_strclr(char *s);
void					ft_strdel(char **as);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strmap(const char *s,
		char (*f)(char));
char					*ft_strmapi(char const *s,
		char (*f)(unsigned int, char));
char					*ft_strnew(size_t size);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_atoi(char *nb);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
void					ft_putnbr(int n);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_lstadd(t_list **alst, t_list *newl);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)
		(void *, size_t));
char					**ft_strsplit(char const *s, char c);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char					*ft_strtrim(char const *s);
char					*ft_itoa(int n);
int						ft_ncuvinte(char const *s, char c);
int						ft_lcuvint(char const *s, char c, int i);
int						ft_stringlen(char const *s);
int						ft_digits(int n);
char					*ft_fillstring(char *str, int n, int x, int s);
#endif
