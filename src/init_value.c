/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:53:10 by jukim             #+#    #+#             */
/*   Updated: 2018/04/27 19:22:06 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_value(t_yeee *p)
{
	p->tran_x = 10;
	p->tran_y = 10;
	p->vtran_x = 10;
	p->vtran_y = 10;
	p->mx = 2;
	p->a = -1;
	p->color = 1;
	p->z_up = 0;
	p->zoom = 0;
	p->window_x >= p->window_y ? (p->l_w = p->window_x) : (p->l_w = p->window_y);
	p->mid_wx = p->window_x / 2;
	p->mid_wy = p->window_y / 2;
}
