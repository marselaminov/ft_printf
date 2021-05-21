/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:25:00 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/19 21:28:46 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_char(t_struct *f, char *str)
{
	int		len;

	if (f->precision > 0 && f->precision < ft_strlen(str))
		len = f->precision;
	else
	{
		if (f->dot && f->precision <= 0)
			len = 0;
		else
			len = ft_strlen(str);
	}
	return (len);
}

static int	count_zero(t_struct *f, int len)
{
	int		zero1;

	if (f->width > len && f->zero)
		zero1 = f->width - len;
	else
		zero1 = 0;
	return (zero1);
}

static int	count_space(t_struct *f, int len, int zero1)
{
	int		space;

	if (f->width > len && !zero1)
		space = f->width - len;
	else
		space = 0;
	return (space);
}

void		type_string(va_list args, t_struct *f)
{
	char	*str;
	int		len;
	int		space;
	int		zero1;

	if (!(str = va_arg(args, char*)))
		str = "(null)";
	len = count_char(f, str);
	zero1 = count_zero(f, len);
	space = count_space(f, len, zero1);
	f->result += len + space + zero1;
	if (!f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (f->zero)
		while (zero1-- > 0)
			ft_putchar_fd('0', 1);
	while (len--)
		ft_putchar_fd(*str++, 1);
	if (f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
