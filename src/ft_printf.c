/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:22:15 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/19 13:48:13 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	f;

	f.index = 0;
	f.result = 0;
	zero_struct(&f);
	va_start(args, format);
	while (format[f.index])
	{
		if (format[f.index] == '%')
			conversions(format, args, &f);
		else
		{
			ft_putchar_fd(format[f.index], 1);
			f.result++;
		}
		f.index++;
	}
	va_end(args);
	return (f.result);
}
