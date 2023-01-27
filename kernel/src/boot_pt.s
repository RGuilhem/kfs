# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    boot_pt.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 00:25:06 by graux             #+#    #+#              #
#    Updated: 2023/01/27 00:57:58 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

/*
.set PAGE_SIZE, 0x1000
.set ENTRIES_PER_PT, 0x1000
.set PAGE_PRESENT, 0x001
.set PAGE_WRITE, 0x002
.set KERN_OFF, 0xC0000000

offset, might be dodgy
.section .data
.align PAGE_SIZE
.global BootP4
BootP4:
  .long offset, BootP3 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
  .rept ENTRIES_PER_PT - 1
    .long 0
  .endr
  .long offset, BootP3 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
BootP3:
	.long offset, BootP2 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
	.rept ENTRIES_PER_PT - 1
	.long 0
	.endr
BootP2:
	.long offset, BootP1 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
	.rept ENTRIES_PER_PT - 1
    .long 0
	.endr
BootP1:
	.set i, 0
	.rept ENTRIES_PER_PT
    .long (i << 12) + (PAGE_PRESENT | PAGE_WRITE)
	.set i, (i+1)
	.endr
*/

.intel_syntax noprefix

.set PAGE_SIZE, 0x1000
.set ENTRIES_PER_PT, 0x1000
.set PAGE_PRESENT, 0x001
.set PAGE_WRITE, 0x002
.set KERN_OFF, 0xC0000000

.section .data
.align PAGE_SIZE
.global BootP4
BootP4:
  .long offset BootP3 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
  .rept ENTRIES_PER_PT - 2
    .quad 0
  .endr
  .long offset BootP3 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
BootP3:
  .long offset BootP2 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
  .rept ENTRIES_PER_PT - 1
    .long 0
  .endr
BootP2:
  .long offset BootP1 - KERN_OFF + (PAGE_PRESENT | PAGE_WRITE)
  .rept ENTRIES_PER_PT - 1
    .long 0
  .endr
BootP1:
  .set i, 0
  .rept ENTRIES_PER_PT
    .long (i << 12) + (PAGE_PRESENT | PAGE_WRITE)
    .set i, (i+1)
  .endr

