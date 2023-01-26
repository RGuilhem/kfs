/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:49 by graux             #+#    #+#             */
/*   Updated: 2023/01/26 16:00:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"
#include "gdt.h"
#include "kfs/phys_mem.h"

void	kernel_main(void)
{
	printf("Entered high level kernel\n");
	printf("KERNEL FROM SCRATCH V0: by graux\n");
}
