/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:09:46 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 13:57:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "kernel.h"

static void	ft_putnbr_fd_rec(long n)
{
	if (n < 0)
	{
		vga_putchar('-');
		ft_putnbr_fd_rec(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd_rec(n / 10);
		ft_putnbr_fd_rec(n % 10);
	}
	else
		vga_putchar(n + '0');
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd_rec(n);
}
