/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:41:21 by jukim             #+#    #+#             */
/*   Updated: 2018/04/27 15:41:41 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_xyz(t_yeee *p)
{
	int y;
	int fd;

	y = 0;
	fd = open(p->av, O_RDONLY);
	get_xy(fd, p);
	close(fd);
	malloc_array(p);
	fd = open(p->av, O_RDONLY);
	while ((get_next_line(fd, &p->line) == 1))
	{
		get_z(y, p);
		free(p->line);
		y++;
		p->line = NULL;
	}
	close(fd);
	p->x_mid = p->xsize / 2;
	p->y_mid = p->ysize / 2;
}

void	get_z(int y, t_yeee *p)
{
	char **r;
	int x;

	x = -1;
	r = ft_strsplit(p->line, ' ');
	while (r[++x] != NULL)
	{
		p->q[y][x].z = ft_atoi(r[x]);
		p->u[x][y].z = p->q[y][x].z;
		if (p->q[y][x].z != 0)
			p->v[y][x] = (3 * p->q[y][x].z);
		free(r[x]);
	}
	free(r);
}

void	get_xy(int fd, t_yeee *p)
{
	int c;

	c = 0;
	p->line = NULL;
	p->ysize = 0;
	while (get_next_line(fd, &p->line) == 1)
	{
		if (c == 0)
			p->xsize = point_count(p->line, ' ');
		free(p->line);
		p->line = NULL;
		p->ysize++;
		c++;
	}
	p->larger_xy = ((p->xsize > p->ysize) ? (p->xsize) : (p->ysize));
}

void	malloc_array(t_yeee *p)
{
	int x;

	x = -1;
	/*	p->u = (t_weee**)malloc(sizeof(t_weee*) * (p->xsize + 1));
	while (++x < p->xsize)
		p->u[x] = (t_weee*)malloc(sizeof(t_weee) * (p->ysize + 1));
	x = -1;
	p->q = (t_weee**)malloc(sizeof(t_weee*) * (p->ysize + 1));
	p->v = (int**)malloc(sizeof(int*) * (p->ysize + 1));
	p->c = (int**)malloc(sizeof(int*) * (p->ysize + 1));
	while (++x < p->ysize)
	{
		p->q[x] = (t_weee*)malloc(sizeof(t_weee) + (p->xsize + 1));
		p->v[x] = (int*)malloc(sizeof(int) * (p->xsize + 1));
		p->c[x] = (int*)malloc(sizeof(int) * (p->xsize + 1));
	}*/
	p->u = (t_weee**)malloc(sizeof(t_weee*) * (p->xsize + 1));
	while (++x < p->xsize)
		p->u[x] = (t_weee*)malloc(sizeof(t_weee) * (p->ysize + 1));
	x = -1;
	p->q = (t_weee**)malloc(sizeof(t_weee*) * (p->ysize + 1));
	while (++x < p->ysize)
		p->q[x] = (t_weee*)malloc(sizeof(t_weee) * (p->xsize + 1));
	x = -1;
	p->v = (int**)malloc(sizeof(int*) * (p->ysize + 1));
	while (++x < p->ysize)
		p->v[x] = (int*)malloc(sizeof(int) * (p->xsize + 1));
	x = -1;
	p->c = (int**)malloc(sizeof(int*) * (p->ysize + 1));
	while (++x < p->ysize)
		p->c[x] = (int*)malloc(sizeof(int) * (p->xsize + 1));
}
