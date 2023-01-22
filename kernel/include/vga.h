/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:40:24 by graux             #+#    #+#             */
/*   Updated: 2023/01/22 14:34:43 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VGA_H
# define VGA_H

# include <stdint.h>
# include <stddef.h>

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

static inline uint8_t	vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return (fg | bg << 4);
}

static inline uint16_t	vga_entry(unsigned char uc, uint8_t color)
{
	return ((uint16_t) uc | (uint16_t) color << 8);
}

void		vga_initialize(void);
void		vga_clear(void);
void		vga_setcolor(uint8_t color);
void		vga_putentry_at(char c, uint8_t color, size_t x, size_t y);
void		vga_putchar(char c);
void		vga_write(const char *data, size_t size);
void		vga_putstr(const char *data);
void		vga_move_cursor(int	x, int y);
uint16_t	vga_get_cursor_pos(void);
void		vga_scroll(size_t line);
void		vga_delete_last_line(void);

#endif
