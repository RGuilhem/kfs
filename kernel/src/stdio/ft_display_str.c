/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:50 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 14:12:25 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include "kernel.h"

void	ft_display_str(t_md *md)
{
	int		i;
	char	*str;

	str = va_arg(md->args, char *);
	i = 0;
	if (str)
	{
		md->total_len += (unsigned long) strlen(str);
		vga_putstr(str);
	}
	else
	{
		md->total_len += 6;
		vga_putstr("(null)");
	}
	md = ft_reset_format(md);
}
