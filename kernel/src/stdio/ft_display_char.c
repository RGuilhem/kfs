/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:12:43 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 13:19:59 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "kernel.h"

void	ft_display_char(t_md *md)
{
	char	c;
	int		i;

	c = (char) va_arg(md->args, int);
	i = 0;
	if (md->dash)
	{
		md->total_len += 1;
		vga_putchar(c);
		while (++i < md->width)
		{
			md->total_len += 1;
			vga_putchar(' ');
		}
	}
	else
	{
		while (++i < md->width - 1)
		{
			md->total_len += 1;
			vga_putchar(' ');
		}
		md->total_len += 1;
		vga_putchar(c);
	}
	md = ft_reset_format(md);
}
