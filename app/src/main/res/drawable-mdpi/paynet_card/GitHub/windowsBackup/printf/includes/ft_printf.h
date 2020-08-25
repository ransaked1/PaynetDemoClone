/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:30:11 by dbraghis          #+#    #+#             */
/*   Updated: 2017/02/18 15:30:14 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <wchar.h>
# include <inttypes.h>
# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum	e_type
{
	NO_TYPE,
	T_INT,
	T_LONG,
	T_LONG_LONG,
	T_SHORT,
	T_CHAR,
	T_INTMAX_T,
	T_UNS_INT,
	T_UNS_LONG,
	T_UNS_LONG_LONG,
	T_UNS_SHORT,
	T_UNS_CHAR,
	T_UINTMAX_T,
	T_SIZE_T,
	T_SSIZE_T,
	T_WINT_T,
	T_WCHAR_T,
	T_WCHAR_T_PTR,
	T_CHAR_PTR,
	T_VOID_PTR,
	T_NOT_VALID_TYPE,
}				t_type;

typedef struct	s_format
{
	int		precision;
	int		min_width;
	int		modifier;

	int		hashtag;
	int		minus;
	int		plus;
	int		zero;
	int		space;

	t_type	type;
	char	format;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_startprint(const char *format, va_list *formatpointer);
int				ft_analyze(va_list *argument, char **i);
char			*ft_arg_parse(t_format *format, char *i, int *modifier);
int				ft_parsstr(char *ptr, char *str);
int				ft_strmod(char	*ptr);
int				ft_find(char **s, char c);
int				ft_proceed_ptr(t_format *format, char *arg);
wchar_t			*ft_get_argument_ptr(va_list ap);
int				ft_get_argument(t_format *options, va_list ap);
char			*ft_itoa_base(unsigned long long n, char *base);
int				ft_arg_modifier(char *str);
int				to_find(char *s, char c);
int				ft_ismodifier(char *str);
int				ft_isflag(char *str);
int				ft_arg_flags(char *str, t_format *format);
int				ft_isspec(char *str);
int				ft_arg_width(char *str, t_format *format);
int				ft_arg_precision(char *str, t_format *format);
t_format		*ft_check_flags(t_format *format);
t_format		*ft_apply_modifier(t_format *format, int modifier);
int				ft_arg_get(va_list ap, t_format *format);
t_type			ft_apply_l_modifier(char specifier);
t_type			ft_apply_ll_modifier(char specifier);
t_type			ft_apply_h_modifier(char specifier);
t_type			ft_apply_hh_modifier(char specifier);
wchar_t			*ft_get_ptr_arg(t_format *format, va_list ap);
int				ft_proceed(t_format *format, wchar_t *arg);
int				ft_proceed_int(t_format *format, char *arg);
int				ft_proceed_str(t_format *format, char *arg);
int				ft_proceed_char(t_format *format, char *arg);
int				ft_proceed_wchar(t_format *format, wchar_t *arg);
int				ft_proceed_wstr(t_format *format, wchar_t *arg);
int				ft_putwstr(wchar_t *str);
int				ft_putwchar(wint_t x);
char			*ft_apply_width(t_format *format, char *arg, void *orig_arg);
wchar_t			*ft_apply_flags(t_format *format, wchar_t *arg,
		void *orig_arg);
wchar_t			*ft_apply_width_wstr(t_format *format, wchar_t *arg,
		void *orig_arg);
char			*ft_apply_sharp_flag_hexa(char specifier, int precision,
		t_format *format, char *arg);
wchar_t			*ft_apply_zero_flag_wstr(int width, wchar_t *arg);
int				ft_proceed_not_valid_type(t_format *format, char *arg);
char			*ft_apply_precision_ptr(t_format *format,
		char *arg, unsigned long fatoi);
char			*ft_prepend_zero(int precision, char *arg);
char			*ft_get_zero(int len);
wchar_t			*ft_get_zero_wstr(int len);
char			*ft_apply_precision(t_format *format, char *arg);
char			*ft_apply_precision_str(t_format *format, char *arg);
wchar_t			*ft_apply_precision_wstr(t_format *format, wchar_t *arg);
void			ft_arg_flags1(char *str, t_format *format);
int				ft_isvalid(char *format);
#endif
