# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    linker.ld                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:14:23 by graux             #+#    #+#              #
#    Updated: 2023/01/26 12:10:29 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)

SECTIONS
{
	. = 1M;

	_kernel_start = .;
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
	_kernel_end = .;
}
