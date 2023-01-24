/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:50 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 13:19:24 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
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
