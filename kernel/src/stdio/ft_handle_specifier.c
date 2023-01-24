/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:35:30 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 13:23:45 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "kfs/error.h"

// specifiers: : cspdiuxX%
void	ft_handle_specifier(int *pos, t_md *md, const char *format)
{
	if (format[*pos] == 'c')
		ft_display_char(md);
	else if (format[*pos] == 's')
		ft_display_str(md);
	else if (format[*pos] == 'p')
		ft_display_pointer(md);
	else if (format[*pos] == 'u')
		ft_display_unsigned(md);
	else if (format[*pos] == 'i' || format[*pos] == 'd')
		ft_display_decimal(md);
	else if (format[*pos] == 'x' || format[*pos] == 'X')
		ft_display_hex(*pos, md, format);
	else if (format[*pos] == '%')
	{
		vga_putchar('%');
		md->total_len += 1;
	}
	else
		print_err("Unknown specifier", ERR_INVA);
	(*pos)++;
}
