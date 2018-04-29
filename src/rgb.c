/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:05:23 by jukim             #+#    #+#             */
/*   Updated: 2018/04/28 21:15:47 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_rgbh(t_yeee *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->ysize)
	{
		j = -1;
		while (++j < p->xsize)
		{
			if (p->color == 1)
			{
				p->fcolor[i][j] = p->q[i][j].f;
				p->q[i][j].r = 0xFFFFFF;
			}
			else if (p->color == 2)
				rgbh_twothree(p, i, j);
			else if (p->color == 3)
				rgbh_twothree(p, i, j);
			else if (p->color == 4)
			{
				p->fcolor[i][j] = 0;
				p->q[i][j].r = p->cc * (i * j + 1);
			}
		}
	}
}

void	rgbh_twothree(t_yeee *p, int i, int j)
{
	if (p->color == 2)
	{
		p->fcolor[i][j] = 0;
		if (p->q[i][j].z == 0 && p->q[i][j + 1].z != 0)
			p->q[i][j].r = 0xbf3eff;
		else if (p->q[i][j].z != 0 && p->q[i][j + 1].z == 0)
			p->q[i][j].r = 0xbf3eff;
		else if (p->q[i][j].z != 0)
			p->q[i][j].r = 0xff3e96;
		else if (p->q[i][j].z == 0)
			p->q[i][j].r = 0xffaeb9;
	}
	else if (p->color == 3)
	{
		p->fcolor[i][j] = 0;
		if (p->q[i][j].z == 0 && p->q[i][j + 1].z != 0)
			p->q[i][j].r = 0xffd700;
		else if (p->q[i][j].z != 0 && p->q[i][j + 1].z == 0)
			p->q[i][j].r = 0xffd700;
		else if (p->q[i][j].z != 0)
			p->q[i][j].r = 0xfffacd;
		else if (p->q[i][j].z == 0)
			p->q[i][j].r = 0xff8c00;
	}
}

void	fdf_rgbv(t_yeee *p)
{
	int i;
	int j;

	i = -1;
	p->cc = 1234567;
	while (++i < p->xsize)
	{
		j = -1;
		while (++j < p->ysize)
		{
			if (p->color == 1)
				p->u[i][j].r = 0xFFFFFF;
			else if (p->color == 2)
				rgbv_twothree(p, i, j);
			else if (p->color == 3)
				rgbv_twothree(p, i, j);
			else if (p->color == 4)
				p->u[i][j].r = p->cc * (i * j + 1);
		}
	}
}

void	rgbv_twothree(t_yeee *p, int i, int j)
{
	if (p->color == 2)
	{
		if (p->u[i][j].z == 0 && p->u[i][j + 1].z != 0)
			p->u[i][j].r = 0xbf3eff;
		else if (p->u[i][j].z != 0 && p->u[i][j + 1].z == 0)
			p->u[i][j].r = 0xbf3eff;
		else if (p->u[i][j].z != 0)
			p->u[i][j].r = 0xff3e96;
		else if (p->u[i][j].z == 0)
			p->u[i][j].r = 0xffaeb9;
	}
	else if (p->color == 3)
	{
		if (p->u[i][j].z == 0 && p->u[i][j + 1].z != 0)
			p->u[i][j].r = 0xffd700;
		else if (p->u[i][j].z != 0 && p->u[i][j + 1].z == 0)
			p->u[i][j].r = 0xffd700;
		else if (p->u[i][j].z != 0)
			p->u[i][j].r = 0xfffacd;
		else if (p->u[i][j].z == 0)
			p->u[i][j].r = 0xff8c00;
	}
}
