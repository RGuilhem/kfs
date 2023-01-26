/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phys_mem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:05:10 by graux             #+#    #+#             */
/*   Updated: 2023/01/26 14:20:27 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYS_MEM_H
# define PHYS_MEM_H

# include <stdint.h>

# define PAGE_SIZE 4092

void	add_phys_map_zone(uint32_t base_addr, uint32_t length, uint32_t type);
void	mark_reserved_zones(uint32_t ram_size);

#endif
