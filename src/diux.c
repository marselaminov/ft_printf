/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:24:30 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/20 17:32:18 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnbr_fd(unsigned int n, char *str, int fd)
{
	size_t	size_str;

	size_str = ft_strlen(str);
	if (n / size_str > 0)
		ft_putnbr_fd(n / size_str, str, fd);
	ft_putchar_fd(str[n % size_str], fd);
}

static int		ft_num_len(unsigned int num, int str_size)
{
	size_t	len;

	len = 1;
	while (num / str_size > 0)
	{
		len++;
		num = num / str_size;
	}
	return (len);
}

static int		get_fillers(t_struct *f, int *len, int *zero1, unsigned int num)
{
	int		space;

	space = 0;
	if (f->negative)
		(*len)++;
	if (f->dot && f->precision <= 0 && !num)
		*len = 0;
	if (f->precision > *len)
		*zero1 = f->precision - *len;
	else if (f->width > *len && f->zero)
		*zero1 = f->width - *len;
	else
		*zero1 = 0;
	if (*zero1 > 0)
		*len = *len + *zero1;
	else
		*len = *len + 0;
	if (f->width > *len && !f->zero)
		space = f->width - *len;
	else
		space = 0;
	return (space);
}

static void		handle_flags(t_struct *f, unsigned int num, int len, char *str)
{
	int		zero1;
	int		space;

	space = get_fillers(f, &len, &zero1, num);
	f->result += len + space;
	/*if (num == 0)
		ft_putchar_fd(' ', 1);*/
	if (!f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	f->negative ? ft_putchar_fd('-', 1) : 0;
	while (zero1-- > 0)
		ft_putchar_fd('0', 1);
	if (len)
		ft_putnbr_fd(num, str, 1);
	if (f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void			types_diux(va_list args, char c, t_struct *f)
{
	int				num;
	unsigned int	un_num;

	if (c == 'i' || c == 'd')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			f->negative = 1;
			num = -num;
			f->precision += f->precision > 0 ? 1 : 0;
		}
		handle_flags(f, num, ft_num_len(num, 10), DIGIT);
	}
	if (c == 'u' || c == 'x' || c == 'X')
	{
		un_num = va_arg(args, unsigned int);
		if (c == 'u')
			handle_flags(f, un_num, ft_num_len(un_num, 10), DIGIT);
		else if (c == 'x')
			handle_flags(f, un_num, ft_num_len(un_num, 16), X_LOW);
		else if (c == 'X')
			handle_flags(f, un_num, ft_num_len(un_num, 16), X_UPP);
	}
}
