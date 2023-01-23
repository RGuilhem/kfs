/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:13:42 by graux             #+#    #+#             */
/*   Updated: 2023/01/23 14:40:48 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "kernel.h"

char	*strchr(const char *s, int c)
{
	char	*s_cpy;

	s_cpy = (char *) s;
	while (*s_cpy)
	{
		if (*s_cpy == (char) c)
			return (s_cpy);
		s_cpy++;
	}
	if (*s_cpy == (char) c)
		return (s_cpy);
	return (NULL);
}
