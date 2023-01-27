# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    boot.s                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 22:40:50 by graux             #+#    #+#              #
#    Updated: 2023/01/27 01:10:28 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "kfs/paging.h"

.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, to prove we are multiboot */
 
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
 
.section .bss
.align 16
.global stack_bottom
stack_bottom:
.skip 16384 # 16 KiB
.global stack_top
stack_top:
 
/*
The linker script specifies _start as the entry point to the kernel and the
bootloader will jump to this position once the kernel has been loaded
*/
.section .text
.global _start
.type _start, @function
_start:
	cli
	mov $stack_top, %esp
	
	#Memory management setup
	push %eax
	push %ebx
	call detect_memory
 
	call init_gdt
 
	call kernel_main
 
	cli
1:	hlt
	jmp 1b
 
.size _start, . - _start 
