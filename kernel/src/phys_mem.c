/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phys_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:03:39 by graux             #+#    #+#             */
/*   Updated: 2023/01/26 14:25:55 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "stdio.h"
#include "multiboot.h"
#include "kfs/phys_mem.h"

extern uint32_t _kernel_end;
extern uint32_t _kernel_start;
//bit map of available mem 1 == used 0 == available
uint32_t *phys_map = &_kernel_end;
uint32_t phys_map_entries = 0;

static void	clear_entry(uint32_t entry)
{
	uint32_t index = entry / 32;
	uint32_t offset = entry % 32;
	uint32_t mask = 0xffffffff ^ (1 << offset); 
	phys_map[index] &= mask;
}

static void	set_entry(uint32_t entry)
{
	uint32_t index = entry / 32;
	uint32_t offset = entry % 32;
	phys_map[index] |= (1 << offset);
}

void	add_phys_map_zone(uint32_t base_addr, uint32_t length, uint32_t type)
{
	for (uint32_t i = 0; i < length; i += PAGE_SIZE)
	{
		uint32_t entry = (base_addr + i) / PAGE_SIZE;
		if (type == MULTIBOOT_MEMORY_AVAILABLE)
			clear_entry(entry);
		else
			set_entry(entry);
		phys_map_entries++;
	}
}

void	mark_reserved_zones(uint32_t ram_size)
{
	printf("\nMarking reserved memory areas\n");
	printf("Number of memory pages: %d == %0x\n\n", phys_map_entries,
			phys_map_entries);
	for (uint32_t addr = 0; addr < ram_size; addr += PAGE_SIZE)
	{
		//TODO test reserved zone and mark them
	}
}
