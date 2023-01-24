/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:28:15 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 13:19:47 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdio.h"

static void	ft_plus(int *i, t_md *md)
{
	if (md->sign)
	{
		md->total_len += 1;
		vga_putchar('+');
		(*i)++;
	}
}

static int	ft_num_len(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

void	ft_display_decimal(t_md *md)
{
	int	i;
	int	num;

	num = va_arg(md->args, int);
	i = 0;
	if (md->dash)
	{
		ft_plus(&i, md);
		ft_putnbr(num);
		md->total_len += ft_num_len(num);
		i += ft_num_len(num);
		while (i++ < md->width)
		{
			md->total_len += 1;
			vga_putchar(' ');
		}
	}
	else
	{
		while (i < md->width && md->width - i < ft_num_len(num))
		{
			md->total_len += 1;
			vga_putchar(' ');
			i++;
		}
		ft_plus(&i, md);
		ft_putnbr(num);
		md->total_len += ft_num_len(num);
	}
}
