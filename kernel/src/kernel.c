/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:49 by graux             #+#    #+#             */
/*   Updated: 2023/01/20 15:10:17 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"

void	kernel_main(void)
{
	vga_initialize();
	printf("42\n");
}
