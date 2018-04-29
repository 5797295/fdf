/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 20:50:32 by jukim             #+#    #+#             */
/*   Updated: 2018/04/28 20:51:12 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
