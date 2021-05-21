/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:24:21 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/20 10:47:33 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_long_fd(unsigned long int n, char *str, int fd)
{
	size_t	size_str;

	size_str = ft_strlen(str);
	if (n / size_str > 0)
		ft_putnbr_long_fd(n / size_str, str, fd);
	ft_putchar_fd(str[n % size_str], fd);
}

static int	ft_num_len(unsigned long int num, int str_size)
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

void		type_pointer(va_list args, t_struct *f)
{
	unsigned long int	adress;
	int					len;
	int					space;
	int					precision1;

	adress = va_arg(args, unsigned long int);
	len = ft_num_len(adress, 16);
	precision1 = (f->precision > len) ? f->precision - len : 0;
	if (f->dot && f->precision <= 0 && adress == 0)
		len = 2;
	else
		len = len + 2;
	space = (f->width > len) ? f->width - len : 0;
	f->result += len + space + precision1;
	if (!f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	write(1, "0x", 2);
	while (precision1-- > 0)
		ft_putchar_fd('0', 1);
	if (len > 2 && !(f->dot && f->precision == -1))
		ft_putnbr_long_fd(adress, X_LOW, 1);
	if (f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
