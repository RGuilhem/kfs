/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:29:25 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 13:19:39 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "kernel.h"

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthex_fd_rec(unsigned int n, int fd, char offset)
{
	if (n >= 16)
	{
		ft_puthex_fd_rec(n / 16, fd, offset);
		ft_puthex_fd_rec(n % 16, fd, offset);
	}
	else
	{
		if (n < 10)
			vga_putchar(n + '0');
		else
			vga_putchar(n - 10 + 'a' - offset);
	}
}

void	ft_display_hex(int pos, t_md *md, const char *format)
{
	unsigned int	num;

	num = va_arg(md->args, unsigned int);
	if (format[pos] == 'x')
		ft_puthex_fd_rec(num, 1, 0);
	else
		ft_puthex_fd_rec(num, 1, 'a' - 'A');
	md->total_len += ft_hex_len(num);
}
