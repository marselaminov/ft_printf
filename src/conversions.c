/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:22:29 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/20 15:00:05 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversions(const char *format, va_list args, t_struct *f)
{
	parse_flags(format, args, f);
	if (format[f->index] == 'c')
		type_char(args, f);
	else if (format[f->index] == 's')
		type_string(args, f);
	else if (format[f->index] == 'p')
		type_pointer(args, f);
	else if (format[f->index] == 'd' || format[f->index] == 'i' ||
	format[f->index] == 'u' || format[f->index] == 'x' ||
	format[f->index] == 'X')
		types_diux(args, format[f->index], f);
	else if (format[f->index] == '%')
		type_percent(f);
	else
	{
		write(1, "%", 1);
		f->index--;
		f->result++;
	}
	zero_struct(f);
}
