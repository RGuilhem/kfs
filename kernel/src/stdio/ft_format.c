/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:46:04 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 13:43:25 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "ft_format.h"
#include "ft_specifier.h"

t_md	*ft_reset_format(t_md *md)
{
	md->width = 0;
	md->precision = 0;
	md->zero_pad = 0;
	md->point = 0;
	md->dash = 0;
	md->sign = 0;
	md->is_zero = 0;
	md->percent = 0;
	md->space = 0;
	md->hashtag = 0;
	return (md);
}

t_md	*ft_init_format(t_md *md)
{
	md = ft_reset_format(md);
	md->total_len = 0;
	return (md);
}

void	ft_handle_flags(int *pos, t_md *md, const char *format)
{
	while (strchr("-+ #0", format[*pos]))
	{
		if (format[*pos] == '-')
			md->dash = 1;
		if (format[*pos] == '+')
			md->sign = 1;
		if (format[*pos] == ' ')
			md->space = 1;
		if (format[*pos] == '#')
			md->hashtag = 1;
		if (format[*pos] == '0')
			md->zero_pad = 1;
		(*pos)++;
	}
}
