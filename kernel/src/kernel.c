/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:49 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 16:56:37 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"
#include "gdt.h"

void	kernel_main(void)
{
	extern const uint32_t stack_top[];
	register uint32_t	esp asm("esp");
	struct gdtr gdt;
	asm ("sgdt %0"
			: "=m" (gdt));
	vga_initialize();
	printf("KERNEL FROM SCRATCH V0: by graux\n");
	printf("stack_top:    %p\n", stack_top);
	printf("esp: %p\n", esp);
	printf("gdt base addr: %p\n", gdt.base);
	//for (int offset = 0; offset < 40; offset += 4)
		//printf("%X\n", *(stack_top - offset));
}
