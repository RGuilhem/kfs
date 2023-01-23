/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:49 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 14:49:29 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"

void	kernel_main(void)
{
	vga_initialize();
	ft_printf("KERNEL FROM SCRATCH V0: by graux\n");
	for (char c = 'A'; c <= 'T'; c++)
		ft_printf("Hello world %d\n", c);
}
