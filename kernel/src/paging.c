/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:30:37 by graux             #+#    #+#             */
/*   Updated: 2023/01/26 20:53:33 by graux            ###   ########.fr       */
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

static	void	set_cr3(uint32_t value)
{
	asm("movl %0, %%cr3"
			:
			: "r" (value));
}

void	init_paging(void)
{
	uint32_t *page_dir = alloc_phys_page();
	uint32_t *page_tab;

	for (uint32_t i = 0; i < PAGE_SIZE / 4; i++)
	{
		page_tab = alloc_phys_page();
	}
}
