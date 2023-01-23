/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:18:53 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 13:48:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "kernel.h"

int	ft_printf(const char *format, ...)
{
	t_md	md;
	int		printed_chars;
	int		i;

	i = 0;
	printed_chars = 0;
	va_start(md.args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_handle_flags(&(i), &md, format);
		}
		else
		{
			printed_chars += 1;
			vga_putchar(format[i++]);
		}
	}
	va_end(md.args);
	printed_chars += md.total_len;
	return (printed_chars);
}
