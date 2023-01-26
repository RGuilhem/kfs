/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phys_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:03:39 by graux             #+#    #+#             */
/*   Updated: 2023/01/26 15:20:55 by graux            ###   ########.fr       */
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
static uint32_t phys_map_size;

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

static int	check_page_use(uint32_t page)
{
	uint32_t index = page / 32;
	uint32_t offset = page % 32;
	if ((phys_map[index] >> offset) & 0x1 == PAGE_USED)
		return (PAGE_USED);
	else
		return (PAGE_AVAIL);
}

uint32_t	*alloc_phys_page(void)
{
	uintptr_t page;
	for (page = 0; page < phys_map_entries; page++)
	{
		if (check_page_use(page) == PAGE_AVAIL)
		{
			set_entry(page);
			return ((void *)(page * PAGE_SIZE));
		}
	}
	//TODO implement out of memory behavior
	return (void *)(0);
}

void	dealloc_phys_page(uint32_t *addr)
{
	clear_entry((uintptr_t) addr / PAGE_SIZE);
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
	phys_map_size = phys_map_entries / 32 + 1;
}

void	mark_reserved_zones(uint32_t ram_size)
{
	printf("\nMarking reserved memory areas\n");
	printf("Number of memory pages: %d == %0x\n\n", phys_map_entries,
			phys_map_entries);
	//here addr is an entry num in phys_map
	for (uint32_t addr = 0; addr < ram_size; addr += PAGE_SIZE)
	{
		if (addr < _kernel_end + phys_map_size)
			set_entry(addr);
	}
}
