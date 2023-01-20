/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:49:00 by graux             #+#    #+#             */
/*   Updated: 2023/01/20 14:49:24 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;

	for (size_t i = 0; i < size; i++)
		dst[i] = src[i];
	return dstptr;
}
