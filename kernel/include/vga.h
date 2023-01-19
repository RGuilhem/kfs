/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:40:24 by graux             #+#    #+#             */
/*   Updated: 2023/01/19 23:38:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VGA_H
# define VGA_H

# include <stdint.h>

/* Hardware text mode colors*/
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

void	terminal_initialize(void);
void	terminal_setcolor(uint8_t color);
void	terminal_putentry_at(char c, uint8_t color, size_t x, size_t y);
void	terminal_putchar(char c);
void	terminal_write(const char *data, size_t size);
void	terminal_putstr(const char *data);

#endif
