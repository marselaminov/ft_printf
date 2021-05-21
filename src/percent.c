/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:24:08 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/19 13:49:06 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_percent(t_struct *f)
{
	int space;
	int	zero;

	if (f->width > 1 && f->zero)
		zero = f->width - 1;
	else
		zero = 0;
	if (f->width > 1 && !zero)
		space = f->width - 1;
	else
		space = 0;
	f->result += 1 + zero + space;
	if (!f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (f->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
