/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:17:49 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:47:42 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	while (n-- != 0)
		*((char*)str++) = 0;
}
