/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:07:00 by jukim             #+#    #+#             */
/*   Updated: 2018/04/27 15:40:25 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_horizontally(t_yeee *p)
{
	int i;
	int j;

	i = -1;
	p->gap = (p->l_w - 250) / p->larger_xy;
	while (++i < p->ysize)
	{
		p->y = (i - p->y_mid) * p->gap + p->window_y / 2;
		j = -1;
		while (++j < p->xsize)
		{
			p->x = (j - p->x_mid) * p->gap + p->window_x / 2;
			if (p->q[i][j].z != 0)
			{
				p->q[i][j].x = p->x + p->v[i][j] + 2;
				p->q[i][j].y = p->y - p->v[i][j] + 2;
			}
			else
			{
				p->q[i][j].x = p->x;
				p->q[i][j].y = p->y;
			}
			extra_store(p, i, j);
		}
	}
}

void	store_vertically(t_yeee *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->xsize)
	{
		j = -1;
		while (++j < p->ysize)
		{
			p->u[i][j].a = p->q[j][i].a;
			p->u[i][j].b = p->q[j][i].b;
			p->u[i][j].c = p->q[j][i].c;
		}
	}
}

void	extra_store(t_yeee *p, int i, int j)
{
	p->q[i][j].a = p->q[i][j].x;
	p->q[i][j].b = p->q[i][j].y;
	p->q[i][j].c = p->q[i][j].z;
	p->q[i][j].xx = p->q[i][j].a;
	p->q[i][j].yy = p->q[i][j].b;
	p->q[i][j].zz = p->q[i][j].c;
}
