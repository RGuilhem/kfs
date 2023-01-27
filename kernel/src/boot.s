# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    boot.s                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 22:40:50 by graux             #+#    #+#              #
#    Updated: 2023/01/27 17:19:53 by graux            ###   ########.fr        #
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
 
.section .bss
.align 0x1000
boot_page_tab: .skip (1024 * 4 * 1024)
boot_page_dir: .skip (1024 * 4 * 1)

multiboot_info_addr: .skip 4
multiboot_header_addr: .skip 4

.section .text
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
 
.align 0x1000
.global _start
#.type _start
_start:
	cli
	#save multibot info to be able to use eax and ebx
	movl %eax, (multiboot_header_addr - K_VIRT_BASE)
	movl %ebx, (multiboot_info_addr - K_VIRT_BASE)

	#init pages
	lea (boot_page_tab - K_VIRT_BASE), %eax
	movl $7, %ebx
	movl $(4 * 1024), %ecx
	.Loop1:
	movl %ebx, (%eax)
	addl $4, %eax
	addl $4096, %ebx
	loop .Loop1

	lea (boot_page_tab - K_VIRT_BASE), %eax
	addl $(K_PAGE_NUM * 1024 * 4), %eax
	movl $7, %ebx
	movl $(4 * 1024), %ecx
	.Loop2:
	movl %ebx, (%eax)
	addl $4, %eax
	addl $(4096), %ebx
	loop .Loop2

	lea (boot_page_tab - K_VIRT_BASE), %ebx
	lea (boot_page_dir - K_VIRT_BASE), %edx
	orl $0x7, %ebx
	movl $1024, %ecx
	.Loop3:
	movl %ebx, (%edx)
	addl $4, %edx
	addl $4096, %ebx
	loop .Loop3
	hlt

	lea (boot_page_dir - K_VIRT_BASE), %ecx
	movl %ecx, %cr3 /*load page dir*/

	movl %cr0, %ecx
	orl $0x80000000, %ecx # set paging add 1 for protected
	movl %ecx, %cr0

	#long jump to correct current vaddr in kernel
	lea (start_high_half), %ecx
	ljmp *(%ecx)

start_high_half:
	#unmap identity mapping
	movl $0x00000000, (boot_page_dir)

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
