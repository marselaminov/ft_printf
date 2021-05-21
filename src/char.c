/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:23:58 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/20 10:44:54 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_char(va_list args, t_struct *f)
{
	char	c;
	int		space;

	c = va_arg(args, int);
	if (f->width > 1)
		space = f->width - 1;
	else
		space = 0;
	f->result += 1 + space;
	if (!f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (f->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
