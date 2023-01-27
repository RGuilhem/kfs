# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    linker.ld                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:14:23 by graux             #+#    #+#              #
#    Updated: 2023/01/27 16:25:32 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)

KERNEL_OFFSET = 0xC0000000;
KERNEL_PHYS = 0x00010000;
VIRT = KERNEL_PHYS + KERNEL_OFFSET;

SECTIONS
{
	. = VIRT;

	_kernel_start = .;
	.text ALIGN(4K) : AT(ADDR(.text) - KERNEL_OFFSET)
	{
		*(.text)
	}

	.rodata ALIGN(4K) : AT(ADDR(.rodata) - KERNEL_OFFSET)
	{
		*(.rodata)
	}

	.data ALIGN(4K) : AT(ADDR(.data) - KERNEL_OFFSET)
	{
		*(.data)
	}

	.bss ALIGN(4K) : AT(ADDR(.bss) - KERNEL_OFFSET)
	{
		*(COMMON)
		*(.bss)
	}
	_kernel_end = .;
}
