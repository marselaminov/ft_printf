/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:22:04 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/20 10:33:39 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define DIGIT "0123456789"
# define X_LOW "0123456789abcdef"
# define X_UPP "0123456789ABCDEF"

typedef struct	s_struct
{
	int			index;
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			precision;
	int			negative;
	int			result;
}				t_struct;

int				ft_printf(const char *format, ...);
void			parse_flags(const char *format, va_list args, t_struct *f);
void			type_char(va_list args, t_struct *f);
void			type_string(va_list args, t_struct *f);
void			type_pointer(va_list args, t_struct *f);
void			types_diux(va_list args, char c, t_struct *f);
void			type_percent(t_struct *f);
void			ft_putchar_fd(char c, int fd);
void			zero_struct(t_struct *f);
void			conversions(const char *format, va_list args, t_struct *f);
int				ft_strlen(const char *str);
int				ft_isdigit(int c);

#endif
