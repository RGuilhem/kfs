/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phys_mem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:05:10 by graux             #+#    #+#             */
/*   Updated: 2023/01/27 00:31:19 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHYS_MEM_H
# define PHYS_MEM_H

# include <stdint.h>

# define PAGE_SIZE 0x1000
# define PAGE_AVAIL 0
# define PAGE_USED 1

void	add_phys_map_zone(uint32_t base_addr, uint32_t length, uint32_t type);
void	mark_reserved_zones(uint32_t ram_size);
void	*alloc_phys_page(void);
void	dealloc_phys_page(void *addr);

#endif
