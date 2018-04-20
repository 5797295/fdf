/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:48:46 by jukim             #+#    #+#             */
/*   Updated: 2018/04/18 20:07:07 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "src/libft/libft.h"
# include "src/minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# define BUF 1024

typedef struct	s_yeee
{
	int x;
	int y;
}				t_yeee;

int		hotkey(int key);

/*
** error_line.c
*/

void	usage_error(void);
void	error(char *str, int fd);

/*
** validation.c
*/

void	validation(char *av);
void	check1(char *str, int fd);

#endif
