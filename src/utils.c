/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legunshi <legunshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:23:00 by legunshi          #+#    #+#             */
/*   Updated: 2020/12/20 16:13:29 by legunshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_struct(t_struct *f)
{
	f->zero = 0;
	f->minus = 0;
	f->width = 0;
	f->precision = -1;
	f->negative = 0;
	f->dot = 0;
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
