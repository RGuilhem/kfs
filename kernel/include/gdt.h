/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:58:31 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 13:09:56 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GDT_H
# define GDT_H

# include <stdint.h>

# define GDT_BASE 0x00000800
# define GDT_SIZE 0x0F       /* Possible number of entry in the gdt */

# define KGDT_BASE			0x0
# define KGDT_LIMIT 		0xFFFFF
# define KGDT_CODE_ACCESS	0x9B
# define KGDT_DATA_ACCESS	0x93
# define KGDT_STACK_ACCESS	0x97

# define UGDT_BASE			0x0
# define UGDT_LIMIT			0xFFFFF
# define UGDT_CODE_ACCESS	0xFF
# define UGDT_DATA_ACCESS	0xF3
# define UGDT_STACK_ACCESS	0xF7

# define GDT_OTHER			0x0D

struct gdtr
{
	uint16_t	limit;
	uint32_t	base;
} __attribute__((packed));

struct gdt_descriptor
{
	uint16_t	limit_0_15;
	uint16_t	base_0_15;
	uint8_t		base_16_23;
	uint8_t		access;
	uint8_t		limit_16_19:4;
	uint8_t		other:4;
	uint8_t		base_24_31;
} __attribute__((packed));

void	init_gdt_descriptor(uint32_t base, uint32_t limit, uint8_t access,
							uint8_t other, struct gdt_descriptor *descriptor);
void	init_gdt(void);

#endif
