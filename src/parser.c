/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:22:49 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/20 16:26:36 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_num(const char *format, int *i)
{
	int		n;

	n = 0;
	while (ft_isdigit(format[*i]))
	{
		n = n * 10 + format[*i] - '0';
		(*i)++;
	}
	return (n);
}

static void		zero_and_minus(const char *format, t_struct *f)
{
	while (format[f->index] == '-' || format[f->index] == '0')
	{
		if (format[f->index] == '-')
			f->minus = 1;
		if ((format[f->index] == '0' && !f->minus))
			f->zero = 1;
		f->index++;
	}
}

static void		width(const char *format, va_list args, t_struct *f)
{
	if (format[f->index] == '*')
	{
		f->width = va_arg(args, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->zero = 0;
			f->width *= -1;
		}
		f->index++;
	}
	else
		f->width = get_num(format, &f->index);
}

static	void	precision(const char *format, va_list args, t_struct *f)
{
	f->dot = 1;
	f->index++;
	if (format[f->index] == '*')
	{
		f->precision = va_arg(args, int);
		if (f->precision < 0)
		{
			f->dot = 0;
			f->precision = -1;
		}
		if (f->precision >= 0)
			f->zero = 0;
		f->index++;
	}
	else
	{
		if (ft_isdigit(format[f->index]))
		{
			f->zero = 0;
			f->precision = get_num(format, &f->index);
		}
	}
}

void			parse_flags(const char *format, va_list args, t_struct *f)
{
	f->index++;
	if (format[f->index] == '-' || format[f->index] == '0')
		zero_and_minus(format, f);
	width(format, args, f);
	if (format[f->index] == '.')
		precision(format, args, f);
}
