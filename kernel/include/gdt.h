/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:58:31 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 11:00:32 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GDT_H
# define GDT_H

# include <stdint.h>

# define GDT_BASE 0x00000800
# define GDT_SIZE 0x0F       /* Possible number of entry in the gdt */

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
