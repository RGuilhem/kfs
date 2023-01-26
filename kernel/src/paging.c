/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:30:37 by graux             #+#    #+#             */
/*   Updated: 2023/01/26 21:12:23 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kfs/paging.h"
#include "kfs/error.h"

static	uint32_t read_cr3(void)
{
	uint32_t cr3;
	asm("movl %%cr3, %0" : "=r" (cr3));
	return (cr3);
}

static void	set_cr3(uint32_t value)
{
	asm("movl %0, %%cr3"
			:
			: "r" (value));
}

static void	identity_paging(uint32_t *first_pte, uintptr_t from, int size)
{
	from = from & 0xfffff000; //discard flags
	for (; size > 0; from += PAGE_SIZE, size -= PAGE_SIZE, first_pte++)
		*first_pte = from | PAGE_P;
}

void	init_paging(void)
{
	uint32_t *page_dir = alloc_phys_page();
	uint32_t *page_tab;

	for (uint32_t i = 0; i < PAGE_SIZE / 4; i++)
	{
		
	}
}
