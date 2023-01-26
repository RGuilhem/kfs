/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:50:08 by graux             #+#    #+#             */
/*   Updated: 2023/01/26 11:34:45 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiboot.h"
#include <stdint.h>
#include "stdio.h"

void detect_memory(multiboot_info_t* mbd, uint32_t magic)
{
	vga_initialize();
	printf("MEMORY DETECTION\n");
    if(magic != MULTIBOOT_BOOTLOADER_MAGIC) {
		//TODO panic
        printf("Invalid magic number!");
    }

    /* Check bit 6 to see if we have a valid memory map */
    if(!(mbd->flags >> 6 & 0x1)) {
		//TODO panic
        printf("Invalid memory map given by GRUB bootloader");
    }
	if (mbd->flags & 0x1)
	{
		printf("MEM below 640KB: %d KB\n", mbd->mem_lower);
		printf("MEM above 1 MB : %d MB\n", mbd->mem_upper / 1024);
	}

    /* Loop through the memory map and display the values */
    for(size_t i = 0; i < mbd->mmap_length; 
        i += sizeof(multiboot_memory_map_t)) 
    {
        multiboot_memory_map_t* mmmt = 
			(multiboot_memory_map_t*) (mbd->mmap_addr + i);
        printf("Base Addr: %0X | Length: %0X | Type: %d\n",
            mmmt->addr_low, mmmt->len_low, mmmt->type);

        if(mmmt->type == MULTIBOOT_MEMORY_AVAILABLE) {
            /* 
             * Do something with this memory block!
             * BE WARNED that some of memory shown as availiable is actually 
             * actively being used by the kernel! You'll need to take that
             * into account before writing to memory!
             */
			//TODO init phys memory map
        }
    }
}
