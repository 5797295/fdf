/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:48:46 by jukim             #+#    #+#             */
/*   Updated: 2018/04/27 16:30:33 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "src/libft/libft.h"
# include "src/minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# define BUF 1024

typedef struct	s_weee
{
	float x;
	float y;
	int z;
	float a;
	float b;
	float c;
	float xx;
	float yy;
	int zz;
	int r;
}				t_weee;

typedef struct	s_yeee
{
	t_weee	**q;
	t_weee	**u;
	void	*mlx;
	void	*win;
	float	zoom;
	int		zoom_x;
	int		zoom_y;
	float	x;
	float	y;
	int		n;
	int		m;
	int	 	xsize;
	int	 	ysize;
	char	*line;
	int		tran_x;
	int		tran_y;
	int		vtran_x;
	int		vtran_y;
	float	k;
	float	l;
	int		larger_xy;
	float	z_up;
	float	fb;
	char	*av;
	float	mx;
	int		**v;
	int		**c;
	float	gap;
	int		a;
	int		color;
	float	x_max;
	float	y_max;
	float	x_mid;
	float	y_mid;
	int		window_x;
	int		window_y;
	float	l_w;
}				t_yeee;

/*
** init_value.c
*/

void		init_value(t_yeee *p);

/*
** fdf.c
*/

void		init(t_yeee *p);
int			hotkey(int key, t_yeee *p);
int			point_count(char *s, char c);
void		draw_init(t_yeee *p);
void		draw_xvertex(t_yeee *p);
void		draw_yvertex(t_yeee *p);
void		translation_x(t_yeee *p, int n);
void		translation_y(t_yeee *p, int n);
void		vtranslation_x(t_yeee *p, int n);
void		vtranslation_y(t_yeee *p, int n);
void		zoom(t_yeee *p, int n);
void		reset(t_yeee *p);
void		z_size(t_yeee *p, int n);

/*
** rgb.c
*/

void		fdf_rgbh(t_yeee *p);
void		fdf_rgbv(t_yeee *p);

/*
** error_line.c
*/

void		usage_error(void);
void		error(char *str, int fd);

/*
** validation.c
*/

void		validation(char *av);
void		check1(char *str, int fd);

/*
** store.c
*/

void		store_horizontally(t_yeee *p);
void		store_vertically(t_yeee *p);
void		extra_store(t_yeee *p, int i, int j);

/*
** read.c
*/

void		read_xyz(t_yeee *p);
void		get_z(int y, t_yeee *p);
void		get_xy(int fd, t_yeee *p);
void		malloc_array(t_yeee *p);

#endif
