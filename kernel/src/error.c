/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:54:05 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 12:58:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kfs/error.h"
#include "stdio.h"

int errno;

void	set_errno(enum error_code errnb)
{
	errno = errnb;
}

int		get_errno(void)
{
	return errno;
}

void	print_err(const char *error_msg, enum error_code err_type)
{
	vga_setcolor(vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK));
	printf("ERROR: %d, %s\n", err_type, error_msg);
	vga_reset_color();
}
