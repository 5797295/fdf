/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:29:28 by jukim             #+#    #+#             */
/*   Updated: 2018/04/18 16:35:22 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage_error(void)
{
	ft_putendl("usage: ./fdf <file_name>");
	exit(0);
}

void	error(char *str, int fd)
{
	ft_putendl(str);
	close(fd);
	exit(0);
}
