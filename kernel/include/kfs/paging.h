/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:31:17 by graux             #+#    #+#             */
/*   Updated: 2023/01/27 00:04:01 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAGING_H
# define PAGING_H

# include "kfs/phys_mem.h"

//TODO Create struct for page dir and tables
#define KERNEL_OFFSET 0xC00000000

#ifdef __ASSEMBLER__
#define V2P(a) ((a) - KERNEL_OFFSET)
#define P2V(a) ((a) + KERNEL_OFFSET)
#else
#include <stdint.h>
#define V2P(a) ((uintptr_t)(a) & ~KERNEL_OFFSET)
#define P2V(a) ((uintptr_t)(a) | KERNEL_OFFSET))
#endif

# define PDIR_IND(vaddr) ((uintptr_t) vaddr >> 22)
# define PTAB_IND(vaddr) ((uintptr_t) vaddr >> 12 & 0x3FF) //middle part of vaddr

// define page flags
# define PAGE_G  (1 << 8) //Global
# define PAGE_S  (1 << 7) //For 4MiB pages, not used
# define PAGE_D  (1 << 6) //Determine if page as been written 
# define PAGE_A  (1 << 5) //set if PDE of PTE was read during addr translation
# define PAGE_CD (1 << 4) //cache disable
# define PAGE_WT (1 << 3) //write through
# define PAGE_US (1 << 2) //privilege: set fora access to all
# define PAGE_RW (1 << 1) //read/write: set for write acces readonly otherwise
# define PAGE_P (1)      //present: page is in phys mem

void	get_phys_addr(void *vaddr);
void	map_page(void *paddr, void *vaddr, uint32_t flags);
void	unmap_page(void *vaddr);
void	init_paging(void);

#endif
