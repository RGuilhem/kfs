/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:26:48 by graux             #+#    #+#             */
/*   Updated: 2023/01/20 15:04:50 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO_H
# define STDIO_H

# include "vga.h"

# define EOF (-1)

int	putchar(int ic);
int	puts(const char *str);
int	printf(const char *restrict format, ...);

#endif
