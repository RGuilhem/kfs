/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:51:48 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 13:14:36 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gdt.h"
#include "string.h"

struct gdt_descriptor	kgdt[GDT_SIZE];
struct gdtr				kgdtr;

void	init_gdt_descriptor(uint32_t base, uint32_t limit, uint8_t access,
							uint8_t other, struct gdt_descriptor *descriptor)
{
	descriptor->limit_0_15	= (limit & 0xFFFF);
	descriptor->base_0_15	= (base & 0xFFFF);
	descriptor->base_16_23	= (base & 0xFF0000) >> 16;
	descriptor->access      = access;
	descriptor->limit_16_19 = (limit & 0xF0000) >> 16;
	descriptor->other       = (other & 0xF);
	descriptor->base_24_31  = (limit & 0xFF000000) >> 24;
	return ;
}

void	init_gdt(void)
{
	//TODO: modify for tss;

	init_gdt_descriptor(0x0, 0x0, 0x0, 0x0, &kgdt[0]);
	//Kernel code, data and stack
	init_gdt_descriptor(KGDT_BASE, KGDT_LIMIT, KGDT_CODE_ACCESS, GDT_OTHER, &kgdt[1]);
	init_gdt_descriptor(KGDT_BASE, KGDT_LIMIT, KGDT_DATA_ACCESS, GDT_OTHER, &kgdt[2]);
	init_gdt_descriptor(KGDT_BASE, 0x0, KGDT_STACK_ACCESS, GDT_OTHER, &kgdt[3]);
	//User code, data and stack
	init_gdt_descriptor(UGDT_BASE, UGDT_LIMIT, UGDT_CODE_ACCESS, GDT_OTHER, &kgdt[4]);
	init_gdt_descriptor(UGDT_BASE, UGDT_LIMIT, UGDT_DATA_ACCESS, GDT_OTHER, &kgdt[5]);
	init_gdt_descriptor(UGDT_BASE, 0x0, UGDT_STACK_ACCESS, GDT_OTHER, &kgdt[6]);
	//TODO: create tss gdt entry;
	
	kgdtr.limit = GDT_SIZE * 8;
	kgdtr.base  = GDT_BASE;
	memcpy((char *) kgdtr.base, (char *) kgdt, kgdtr.limit);
	asm("lgdt (kgdtr)");
	asm("movw $0x10, %ax   \n\
		 movw %ax, %ds     \n\
		 movw %ax, %es     \n\
		 movw %ax, %fs     \n\
		 movw %ax, %gs     \n\
		 ljmp $0x08, $next \n\
		 next:             \n");
}
