/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:06 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 14:06:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include "kernel.h"

static int	ft_ptr_len(unsigned long long num)
{
	int					len;

	len = 0;
	if (num == 0)
		return (3);
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len + 2);
}

static void	ft_putptr_fd(unsigned long long n, int fd)
{
	if (n >= 16)
	{
		ft_putptr_fd(n / 16, fd);
		ft_putptr_fd(n % 16, fd);
	}
	else
	{
		if (n < 10)
			vga_putchar(n + '0');
		else
			vga_putchar(n - 10 + 'a');
	}
}

void	ft_display_pointer(t_md *md)
{
	void				*ptr;
	unsigned long long	num;

	ptr = va_arg(md->args, void *);
	num = (unsigned long long) ptr;
	md->total_len += ft_ptr_len(num);
	vga_putstr("0x");
	ft_putptr_fd(num, 1);
}
