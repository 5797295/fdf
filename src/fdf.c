/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:07:41 by jukim             #+#    #+#             */
/*   Updated: 2018/04/27 16:34:55 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	init(t_yeee *p)
{
	fdf_rgbh(p);
	fdf_rgbv(p);
	draw_xvertex(p);
	draw_yvertex(p);
	mlx_key_hook(p->win, hotkey, p);
	mlx_string_put(p->mlx, p->win, 5, 5, 0x4876ff, "[ESC]       - Exit");
	mlx_string_put(p->mlx, p->win, 5, 20, 0x4876ff, "[ARROW KEY] - Translation");
	mlx_string_put(p->mlx, p->win, 5, 35, 0x4876ff, "[I,K]       - Vertex Translation Up/Down");
	mlx_string_put(p->mlx, p->win, 5, 50, 0x4876ff, "[J,L]       - Vertex Translation Left/Right");
	mlx_string_put(p->mlx, p->win, 5, 65, 0x4876ff, "[Z,X]       - Move Vertex Up/Down");
	mlx_string_put(p->mlx, p->win, 5, 80, 0x4876ff, "[1,2,3]     - Change Color");
	mlx_string_put(p->mlx, p->win, 5, 95, 0x4876ff, "[V]         - Reset");
	mlx_loop(p->mlx);
}

void	draw_xvertex(t_yeee *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
			p->k = p->q[i][j].a;
			p->l = p->q[i][j].b;
			while (p->k < p->q[i][j + 1].a)
			{
				mlx_pixel_put(p->mlx, p->win, p->k, ((p->k - p->q[i][j].a) /
							(p->q[i][j + 1].a - p->q[i][j].a) *
							(p->q[i][j + 1].b - p->q[i][j].b) +
							p->q[i][j].b), p->q[i][j].r);
				p->k++;
			}
			while (p->l < p->q[i][j + 1].b)
			{
				mlx_pixel_put(p->mlx, p->win, ((p->l - p->q[i][j].b) /
							(p->q[i][j + 1].b - p->q[i][j].b) *
							(p->q[i][j + 1].a - p->q[i][j].a) +
							p->q[i][j].a), p->l, p->q[i][j].r);
				p->l++;
			}
		}
	}
}

void	draw_yvertex(t_yeee *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->xsize)
	{
		j = -1;
		while (++j < p->ysize)
		{
			p->k = p->u[i][j].a;
			p->l = p->u[i][j].b;
			while (p->k < p->u[i][j + 1].a)
			{
				mlx_pixel_put(p->mlx, p->win, p->k, ((p->k - p->u[i][j].a) /
							(p->u[i][j + 1].a - p->u[i][j].a) *
							(p->u[i][j + 1].b - p->u[i][j].b) +
							p->u[i][j].b), p->u[i][j].r);
				p->k++;
			}
			while (p->l < p->u[i][j + 1].b)
			{
				mlx_pixel_put(p->mlx, p->win, ((p->l - p->u[i][j].b) /
							(p->u[i][j + 1].b - p->u[i][j].b) *
							(p->u[i][j + 1].a - p->u[i][j].a) +
							p->u[i][j].a), p->l, p->u[i][j].r);
				p->l++;
			}
		}
	}
}

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
	key == 78 ? zoom(p, -1) : 0;
	key == 69 ? zoom(p, 1) : 0;
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
		{
			if (p->q[i][j].z != 0)
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
		}
	}
}

void	zoom(t_yeee *p, int n)
{
	int i;
	int j;

	i = -1;
//	p->zoom += n;
	n > 0 ? (p->zoom = 1.1) : (p->zoom = 0.9);
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
		/*	p->zoom_x = (j < (p->xsize / 2) ? p->zoom * (p->xsize / 2 - j) : 0);
			j > (p->xsize / 2) ? p->zoom_x = -p->zoom * (j - p->xsize / 2) : 0;
			p->q[i][j].a = p->q[0][0].xx - p->zoom_x + j * (p->window_x / 2 / p->xsize);
			p->zoom_y = (i < (p->ysize / 2) ? p->zoom * (p->ysize / 2 - i) : 0);
			i > (p->ysize / 2) ? p->zoom_y = -p->zoom * (i - p->ysize / 2) : 0;
			p->q[i][j].b = p->q[0][0].yy - p->zoom_y + i * (p->window_y / 2 / p->ysize);
			printf("q[%d][%d](%f, %f)\n", i, j, p->q[i][j].a, p->q[i][j].b); */
			p->q[i][j].a = p->q[i][j].a * p->zoom;
			p->q[i][j].b = p->q[i][j].b * p->zoom;
		}
	}
}
void	vtranslation_x(t_yeee *p, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
			if (p->q[i][j].z != 0)
			{
				if (n > 0)
					p->q[i][j].a += p->vtran_x;
				else
					p->q[i][j].a -= p->vtran_x;
			}
		}
	}
}

void	vtranslation_y(t_yeee *p, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
			if (p->q[i][j].z != 0)
			{
				if (n > 0)
					p->q[i][j].b += p->vtran_y;
				else
					p->q[i][j].b -= p->vtran_y;
			}
		}
	}
}

void	translation_x(t_yeee *p, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
			if (n > 0)
				p->q[i][j].a += p->tran_x;
			else
				p->q[i][j].a -= p->tran_x;
		}
	}
}

void	translation_y(t_yeee *p, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
			if (n > 0)
				p->q[i][j].b += p->tran_y;
			else
				p->q[i][j].b -= p->tran_y;
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
		get_z(y, p);
		free(p->line);
		y++;
		p->line = NULL;
	}
	close(fd);
	store_horizontally(p);
}

int		point_count(char *s, char c)
{
	int	count;
	int	point;

	count = 0;
	point = 0;
	while (*s != '\0')
	{
		if (point == 1 && *s == c)
			point = 0;
		if (point == 0 && *s != c)
		{
			point = 1;
			count++;
		}
		s++;
	}
	return (count);
}
