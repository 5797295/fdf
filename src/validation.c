/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:17:04 by jukim             #+#    #+#             */
/*   Updated: 2018/04/26 22:27:31 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	validation(char *av)
{
	int		fd;
	int		ret;
	char	str[BUF + 1];

	if ((fd = open(av, O_RDONLY)) < 0)
		error("error: unable to open the file", fd);
	ret =  read(fd, str, BUF);
	if (ret)
		check1(str, fd);
	close(fd);
}

void	check1(char *str, int fd)
{
	int i;

	i = -1;
	if (!*str)
		error("error: file is empty", fd);
	while (str[++i] != '\0')
		if (str[i] < 48 || str[i] > 58)
			if (str[i] != ' ' && str[i] != '\n' && str[i] != '-')
				error("error: invalid input file", fd);
}
