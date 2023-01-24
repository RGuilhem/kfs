/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:16:36 by graux             #+#    #+#             */
/*   Updated: 2023/01/24 12:57:31 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* Look in man errno for error codes */
enum error_code
{
	ERR_DEFAULT	= 0,
	ERRP_PERM	= 1,
	ERR_INVA	= 22,
	ERR_NOSYS	= 78,
};

void	set_errno(enum error_code errnb);
int		get_errno(void);
void	print_err(const char *error_msg, enum error_code err_type);

#endif
