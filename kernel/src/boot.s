# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    boot.s                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 22:40:50 by graux             #+#    #+#              #
#    Updated: 2023/01/27 12:47:35 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, to prove we are multiboot */

.set K_VIRT_BASE, 0xC0000000
.set K_PAGE_NUM, (K_VIRT_BASE >> 22)
 
.section .bss
.align 16
.global stack_bottom
stack_bottom:
.skip 16384 # 16 KiB
.global stack_top
stack_top:
 
.section .data
.align 0x1000
boot_page_dir:
	.long 0x00000083 # first 4mb unmapped later
	.rept (K_PAGE_NUM - 1)
		.long 0 #zero pages before kernel
	.endr
	.long 0x00000083 # kernel first 4mb
	.rept (1024 - K_PAGE_NUM - 1)
		.long 0 #zero pages after kernel
	.endr

.section .text
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
 
.global _start
#.type _start
_start:
	movl (boot_page_dir - K_VIRT_BASE), %ecx
	movl %ecx, %cr3 /*load page dir*/
	
	movl %cr0, %ecx
	orl $0x80000000, %ecx # set paging
	movl %ecx, %cr3

	#long jump to correct current vaddr in kernel
	lea (start_high_half), %ecx
	hlt
	jmp (%ecx)

start_high_half:
	#unmap identity mapping
	hlt
	movl $0x00000000, (boot_page_dir)
	invlpg (0)

	mov $stack_top, %esp
	push %eax #push header magic number
	addl K_VIRT_BASE, %ebx #make multiboot addr virtual 
	push %ebx
	cli
	call detect_memory
/*
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
*/
