/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 00:39:14 by jukim             #+#    #+#             */
/*   Updated: 2018/04/28 21:19:48 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hotkey(int key, t_yeee *p)
{
	mlx_clear_window(p->mlx, p->win);
	if (key == 53)
		exit(0);
	key == 123 ? translation_x(p, -1) : 0;
	key == 124 ? translation_x(p, 1) : 0;
	key == 125 ? translation_y(p, 1) : 0;
	key == 126 ? translation_y(p, -1) : 0;
	key == 34 ? vtranslation_y(p, -1) : 0;
	key == 40 ? vtranslation_y(p, 1) : 0;
	key == 38 ? vtranslation_x(p, -1) : 0;
	key == 37 ? vtranslation_x(p, 1) : 0;
	key == 9 ? reset(p) : 0;
	key == 6 ? z_size(p, 1) : 0;
	key == 7 ? z_size(p, -1) : 0;
	key == 18 ? p->color = 1 : 0;
	key == 19 ? p->color = 2 : 0;
	key == 20 ? p->color = 3 : 0;
	key == 21 ? p->color = 4 : 0;
	(key == 78 || key == 27) ? zoom(p, -1) : 0;
	(key == 69 || key == 24) ? zoom(p, 1) : 0;
	store_vertically(p);
	init(p);
	return (0);
}

void	z_size(t_yeee *p, int n)
{
	int i;
	int j;

	i = -1;
	p->z_up = 7;
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
			if (p->q[i][j].z != 0)
				vertex_up(p, i, j, n);
	}
}

void	vertex_up(t_yeee *p, int i, int j, int n)
{
	if (n > 0)
	{
		p->q[i][j].x = p->q[i][j].a + p->v[i][j] + p->z_up;
		p->q[i][j].y = p->q[i][j].b - p->v[i][j] - p->z_up;
	}
	else
	{
		p->q[i][j].x = p->q[i][j].a - p->v[i][j] - p->z_up;
		p->q[i][j].y = p->q[i][j].b + p->v[i][j] + p->z_up;
	}
	p->q[i][j].a = p->q[i][j].x;
	p->q[i][j].b = p->q[i][j].y;
}

void	zoom(t_yeee *p, int n)
{
	int i;
	int j;

	i = -1;
	p->zoom = (n > 0 ? 1.1 : 0.9);
	p->zoom_x = (n < 0 ? (p->l_w / 20) : (-(p->l_w / 20)));
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
			p->q[i][j].a = p->q[i][j].a * p->zoom + p->zoom_x;
			p->q[i][j].b = p->q[i][j].b * p->zoom + p->zoom_x;
		}
	}
}

void	reset(t_yeee *p)
{
	int fd;
	int y;

	init_value(p);
	y = 0;
	fd = open(p->av, O_RDONLY);
	while ((get_next_line(fd, &p->line) == 1))
	{
		get_z(p, y);
		free(p->line);
		y++;
		p->line = NULL;
	}
	close(fd);
	store_horizontally(p);
}
