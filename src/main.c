/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:46:15 by jukim             #+#    #+#             */
/*   Updated: 2018/04/27 17:32:36 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_yeee p;

	if (ac == 4)
	{
		p.window_x = ft_atoi(av[2]);
		p.window_y = ft_atoi(av[3]);
		if (p.window_x < 500)
			usage_error();
		if (p.window_y < 500)
			usage_error();
		validation(av[1]);
	}
	else
		usage_error();
	init_value(&p);
	p.av = av[1];
	read_xyz(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.window_x, p.window_y, "YEEEEEE");
	store_horizontally(&p);
	store_vertically(&p);
	init(&p);
	return (0);
}
