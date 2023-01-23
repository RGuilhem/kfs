/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:49 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 20:51:46 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"

void	kernel_main(void)
{
	vga_initialize();
	printf("KERNEL FROM SCRATCH V0: by graux\n");
	for (char c = 'A'; c <= 'F'; c++)
	{
		printf("Hello world %c\n", c);
		printf("Hello world %p\n", &c);
	}
}
