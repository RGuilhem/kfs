/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:28:13 by graux             #+#    #+#             */
/*   Updated: 2023/01/20 14:33:35 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "kernel.h"

size_t	strlen(const char *str);
int		memcmp(const void* aptr, const void* bptr, size_t size);
void*	memset(void* bufptr, int value, size_t size);
void*	memmove(void* dstptr, const void* srcptr, size_t size);
void*	memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size);

#endif
