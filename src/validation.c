/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:17:04 by jukim             #+#    #+#             */
/*   Updated: 2018/04/28 22:29:22 by jukim            ###   ########.fr       */
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
	ret = read(fd, str, BUF);
	if (*str == 0)
		error("error: file is empty", fd);
	if (ret)
		check(str, fd);
	close(fd);
}

void	check(char *str, int fd)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			error("error: invalid input file", fd);
		else if (str[i] < ' ' && str[i] != '\n')
			error("error: invalid input file", fd);
		else if (str[i] > ' ' && str[i] < ',')
			error("error: invalid input file", fd);
		else if (str[i] > '-' && str[i] < '0')
			error("error: invalid input file", fd);
		else if (str[i] > '9' && str[i] < 'A')
			error("error: invalid input file", fd);
		else if (str[i] > 'F' && str[i] < 'a')
			error("error: invalid input file", fd);
		else if (str[i] > 'f' && str[i] != 'x')
			error("error: invalid input file", fd);
	}
}
