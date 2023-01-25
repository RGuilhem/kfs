/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:50:08 by graux             #+#    #+#             */
/*   Updated: 2023/01/25 15:17:01 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "multiboot.h"
#include <stdint.h>
#include "stdio.h"

void detect_memory(multiboot_info_t* mbd, uint32_t magic)
{
    /* Make sure the magic number matches for memory mapping*/
    if(magic != MULTIBOOT_BOOTLOADER_MAGIC) {
        //panic("invalid magic number!");
    }

    /* Check bit 6 to see if we have a valid memory map */
    if(!(mbd->flags >> 6 & 0x1)) {
        //panic("invalid memory map given by GRUB bootloader");
    }

    /* Loop through the memory map and display the values */
    for(int i = 0; i < mbd->mmap_length; 
        i += sizeof(multiboot_memory_map_t)) 
    {
        multiboot_memory_map_t* mmmt = 
			(multiboot_memory_map_t*) (mbd->mmap_addr + i);

        printf("Start Addr: %x | Length: %x | Size: %x | Type: %d\n",
            mmmt->addr_low, mmmt->len_low, mmmt->size, mmmt->type);

        if(mmmt->type == MULTIBOOT_MEMORY_AVAILABLE) {
            /* 
             * Do something with this memory block!
             * BE WARNED that some of memory shown as availiable is actually 
             * actively being used by the kernel! You'll need to take that
             * into account before writing to memory!
             */
        }
    }
}
