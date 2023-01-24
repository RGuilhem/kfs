/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:26:48 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 11:01:39 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO_H
# define STDIO_H

# include "vga.h"
# include <stdarg.h>

int		putchar(int ic);
int		puts(const char *str);
int		printf(const char *format, ...);
void	ft_putnbr(int n);

typedef struct s_md
{
	va_list	args;
	int		width;
	int		precision;
	int		zero_pad;
	int		point;
	int		dash;
	int		total_len;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
	int		hashtag;
}	t_md;

t_md	*ft_reset_format(t_md *md);
t_md	*ft_init_format(t_md *md);
void	ft_handle_flags(int *pos, t_md *md, const char *format);
void	ft_handle_width(int *pos, t_md *md, const char *format);
void	ft_handle_prec(int *pos, t_md *md, const char *format);
int		ft_width_len(int *pos, const char *format);
int		ft_num_size(int pos, const char *format);

void	ft_handle_specifier(int *pos, t_md *md, const char *format);
void	ft_display_char(t_md *md);
void	ft_display_str(t_md *md);
void	ft_display_pointer(t_md *md);
void	ft_display_decimal(t_md *md);
void	ft_display_unsigned(t_md *md);
void	ft_display_hex(int pos, t_md *md, const char *format);
#endif
