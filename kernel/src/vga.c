/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:46:57 by graux             #+#    #+#             */
/*   Updated: 2023/01/20 15:43:14 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vga.h"
#include "string.h"
#include "io.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t		vga_row;
size_t		vga_col;
uint8_t		vga_color;
uint16_t	*vga_buffer;

static void	vga_update_cursor()
{
	vga_move_cursor(vga_col, vga_row);
}

void	vga_initialize(void)
{
	vga_row = 0;
	vga_col = 0;
	vga_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	vga_buffer = (uint16_t *) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for (size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index = y * VGA_WIDTH + x;
			vga_buffer[index] = vga_entry(' ', vga_color);
		}
	}
}

void	vga_setcolor(uint8_t color)
{
	vga_color = color;
}

void	vga_putentry_at(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	vga_buffer[index] = vga_entry(c, color);
}

void	vga_putchar(char c)
{
	int				line;
	unsigned char	uc = c;

	if (uc == '\n')
	{
		vga_col = 0;
		vga_row++;
	}
	else
	{
		vga_putentry_at(uc, vga_color, vga_col, vga_row);
		if (++vga_col == VGA_WIDTH) {
			vga_col = 0;
			if (++vga_row == VGA_HEIGHT)
			{
				for(line = 1; line <= VGA_HEIGHT - 1; line++)
					vga_scroll(line);
				vga_delete_last_line();
				vga_row = VGA_HEIGHT - 1;
			}
		}
	}
	vga_update_cursor();
}

void	vga_write(const char *data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		vga_putchar(data[i]);
}

void	vga_putstr(const char *data)
{
	vga_write(data, strlen(data));
}

uint16_t vga_get_cursor_pos(void)
{
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    return pos;
}

void vga_move_cursor(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void vga_scroll(int line)
{
	int loop;
	char c;
/* 
	for(loop = line * (VGA_WIDTH * 2) + 0xB8000; loop < VGA_WIDTH * 2; loop++) {
		c = *loop;
		*(loop - (VGA_WIDTH * 2)) = c;
	}
	*/
}

void vga_delete_last_line(void) 
{
	for (size_t x = 0; x < VGA_WIDTH; x++)
		vga_putentry_at('\0', vga_color, x, vga_row);
	vga_col = 0;
	vga_update_cursor();
}
