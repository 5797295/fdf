/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:07:41 by jukim             #+#    #+#             */
/*   Updated: 2018/04/28 21:03:31 by jukim            ###   ########.fr       */
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
	mlx_hook(p->win, 2, 2, hotkey, p);
	mlx_string_put(p->mlx, p->win, 5, 5, 0x4876ff, "[ESC]       - Exit");
	mlx_string_put(p->mlx, p->win, 5, 20, 0x4876ff,
			"[ARROW KEY] - Translation");
	mlx_string_put(p->mlx, p->win, 5, 35, 0x4876ff,
			"[I,K]       - Vertex Translation Up/Down");
	mlx_string_put(p->mlx, p->win, 5, 50, 0x4876ff,
			"[J,L]       - Vertex Translation Left/Right");
	mlx_string_put(p->mlx, p->win, 5, 65, 0x4876ff,
			"[Z,X]       - Move Vertex Up/Down");
	mlx_string_put(p->mlx, p->win, 5, 80, 0x4876ff,
			"[+,-]       - Zoom In/Out");
	mlx_string_put(p->mlx, p->win, 5, 95, 0x4876ff,
			"[1,2,3,4]   - Change Color");
	mlx_string_put(p->mlx, p->win, 5, 110, 0x4876ff, "[V]         - Reset");
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
			put_xvertex(p, i, j);
		}
	}
}

void	put_xvertex(t_yeee *p, int i, int j)
{
	while (p->k < p->q[i][j + 1].a)
	{
		mlx_pixel_put(p->mlx, p->win, p->k, ((p->k - p->q[i][j].a) /
					(p->q[i][j + 1].a - p->q[i][j].a) *
					(p->q[i][j + 1].b - p->q[i][j].b) + p->q[i][j].b),
				p->fcolor[i][j] != 0 ? p->fcolor[i][j] : p->q[i][j].r);
		p->k++;
	}
	while (p->l < p->q[i][j + 1].b)
	{
		mlx_pixel_put(p->mlx, p->win, ((p->l - p->q[i][j].b) /
					(p->q[i][j + 1].b - p->q[i][j].b) *
					(p->q[i][j + 1].a - p->q[i][j].a) +
					p->q[i][j].a), p->l, p->fcolor[i][j] != 0 ?
				p->fcolor[i][j] : p->q[i][j].r);
		p->l++;
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
			put_yvertex(p, i, j);
		}
	}
}

void	put_yvertex(t_yeee *p, int i, int j)
{
	while (p->k < p->u[i][j + 1].a)
	{
		mlx_pixel_put(p->mlx, p->win, p->k, ((p->k - p->u[i][j].a) /
					(p->u[i][j + 1].a - p->u[i][j].a) *
					(p->u[i][j + 1].b - p->u[i][j].b) + p->u[i][j].b),
				p->fcolor[j][i] != 0 ? p->fcolor[j][i] : p->u[i][j].r);
		p->k++;
	}
	while (p->l < p->u[i][j + 1].b)
	{
		mlx_pixel_put(p->mlx, p->win, ((p->l - p->u[i][j].b) /
					(p->u[i][j + 1].b - p->u[i][j].b) *
					(p->u[i][j + 1].a - p->u[i][j].a) + p->u[i][j].a),
				p->l, p->fcolor[j][i] != 0 ?
				p->fcolor[j][i] : p->u[i][j].r);
		p->l++;
	}
}
