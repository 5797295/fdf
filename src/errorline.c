/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:29:28 by jukim             #+#    #+#             */
/*   Updated: 2018/04/26 20:20:18 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage_error(void)
{
	ft_putendl("usage: ./fdf <file_name> <Window Width> <Window Height>");
	ft_putendl("\t\t- Width and Height must be at least 500.");
	exit(0);
}

void	error(char *str, int fd)
{
	ft_putendl(str);
	close(fd);
	exit(0);
}
