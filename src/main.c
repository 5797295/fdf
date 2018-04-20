/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:46:15 by jukim             #+#    #+#             */
/*   Updated: 2018/04/18 20:07:01 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

int	main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;
	t_yeee place;

	if (ac == 2)
		 validation(av[1]);
	else
		usage_error();
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "YEEEEEE");
	place.x = 90;
	place.y = 90;
	while (place.x < 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, place.x++, place.y++, 0x54ff9f);
		if (place.y == 100)
		{
			place.x += 10;
			place.y = 90;
		}
	}
	place.x = 90;
	place.y = 90;
	while (place.y < 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, place.x++, place.y++, 0x54ff9f);
		if (place.x == 100)
		{
			place.y += 10;
			place.x = 90;
		}
	}
	place.x = 90;
	place.y = 90;
	while (place.x <= 490)
		mlx_pixel_put(mlx_ptr, win_ptr, place.x++, place.y, 0x4876ff);
	place.x = 90;
	place.y = 90;
	while (place.y <= 490)
		mlx_pixel_put(mlx_ptr, win_ptr, place.x, place.y++, 0x4876ff);
	place.x = 100;
	place.y = 100;
	while (place.x <= 500)
	{
		while (place.y <= 500)
//		{
//			if (place.y >= 120 && place.y <= 130)
//				mlx_pixel_put(mlx_ptr, win_ptr, place.x++, place.y++, 0x4876ff);
//			else
				mlx_pixel_put(mlx_ptr, win_ptr, place.x, place.y++, 0x4876ff);
//		}
		place.x = place.x + 20;
		place.y = 100;
	}
	place.x = 100;
	place.y = 100;
	while (place.y <= 500)
	{
		while (place.x <= 500)
			mlx_pixel_put(mlx_ptr, win_ptr, place.x++, place.y, 0x4876ff);
		place.y = place.y + 20;
		place.x = 100;
	}
	mlx_key_hook(win_ptr, hotkey, 0);
	mlx_string_put(mlx_ptr, win_ptr, 5, 5, 0x4876ff, "[ESC] - Exit");
	mlx_loop(mlx_ptr);
	return (0);
}

int		hotkey(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}
