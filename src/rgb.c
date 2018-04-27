/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:05:23 by jukim             #+#    #+#             */
/*   Updated: 2018/04/27 15:34:09 by jukim            ###   ########.fr       */
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
				if (p->q[i][j].z == 0 && p->q[i][j + 1].z != 0)
					p->q[i][j].r = 0xffb90f;
				else if (p->q[i][j].z != 0 && p->q[i][j + 1].z == 0)
					p->q[i][j].r = 0xffb90f;
				else if (p->q[i][j].z != 0)
					p->q[i][j].r = 0x54ff9f;
				else if (p->q[i][j].z == 0)
					p->q[i][j].r = 0xFFFFFF;
			}
			else if (p->color == 2)
			{
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
				if (p->q[i][j].z == 0 && p->q[i][j + 1].z != 0)
					p->q[i][j].r = 0xffd700;
				else if (p->q[i][j].z != 0 && p->q[i][j + 1].z == 0)
					p->q[i][j].r = 0xffd700;
				else if (p->q[i][j].z != 0)
					p->q[i][j].r = 0xfffacd;
				else if (p->q[i][j].z == 0)
					p->q[i][j].r = 0xff8c00;
			}
		//	p->u[j][i].r = p->q[i][j].r;
		}
	}
}

void	fdf_rgbv(t_yeee *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->xsize)
	{
		j = -1;
		while (++j < p->ysize)
		{
	//		p->u[i][j].r = p->q[j][i].r;
			if (p->color == 1)
			{
				if (p->u[i][j].z == 0 && p->u[i][j + 1].z != 0)
					p->u[i][j].r = 0xffb90f;
				else if (p->u[i][j].z != 0 && p->u[i][j + 1].z == 0)
					p->u[i][j].r = 0xffb90f;
				else if (p->u[i][j].z != 0)
					p->u[i][j].r = 0x54ff9f;
				else if (p->u[i][j].z == 0)
					p->u[i][j].r = 0xFFFFFF;
			}
			else if (p->color == 2)
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
	}
}
