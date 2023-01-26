# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    linker.ld                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:14:23 by graux             #+#    #+#              #
#    Updated: 2023/01/27 00:14:45 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)

KERNEL_OFFSET = 0xC0000000;
KERNEL_START = 0x10000;

SECTIONS
{
	. = 1M;

	. = KERNEL_START + KERNEL_OFFSET;
	_kernel_start = .;
	.text : AT(ADDR(.text) - KERNEL_OFFSET)
	{
		*(.multiboot)
		*(.text)
	}

	.rodata : AT(ADDR(.rodata) - KERNEL_OFFSET)
	{
		*(.rodata)
	}

	.data : AT(ADDR(.data) - KERNEL_OFFSET)
	{
		*(.data)
	}

	.bss : AT(ADDR(.bss) - KERNEL_OFFSET)
	{
		*(COMMON)
		*(.bss)
	}
	_kernel_end = .;
}
