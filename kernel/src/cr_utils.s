# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cr_utils.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 13:51:42 by graux             #+#    #+#              #
#    Updated: 2023/01/25 13:59:48 by graux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.global .text read_cr0
.type read_cr0, @function
read_cr0:
	mov cr0, eax
	retn

.global .text write_cr0
.type write_cr0, @function
write_cr0:
	push epb
	mov esp, ebp
	mov (%ebp) + 8, eax
	mov eax, cr0
	pop ebp
	retn

.global .text read_cr3
.type read_cr3, @function
read_cr3:
	mov cr3, eax
	retn

.global .text write_cr3
.type write_cr3, @function
write_cr3:
	push epb
	mov esp, ebp
	mov (%ebp) + 8, eax
	mov eax, cr3
	pop ebp
	retn
