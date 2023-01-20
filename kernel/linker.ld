# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    linker.ld                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:14:23 by graux             #+#    #+#              #
#    Updated: 2023/01/20 12:18:38 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENTRY(_start)

SECTIONS
{
	. = 1M;

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
}
