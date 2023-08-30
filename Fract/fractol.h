/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:31:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/30 08:25:20 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"

# define MAX_ITER 500
# define W 1370
# define H 1100

typedef struct s_complex
{
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		real;
	double		imag;
	double		c_real;
	double		c_imag;
	double		new_real;
	double		new_imag;
	double		old_real;
	double		old_imag;
	double		x;
	double		y;
	int			iter;
	double		z_real;
	double		z_imag;
	uint32_t	color;
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			draw;
	double		zoom;
	double		move_x;
	double		move_y;
}				t_complex;

//common
int			ft_strcmp(char *s1, char *s2);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int			execution(int argc, char **argv, mlx_t *mlx, t_complex *c);
void		zooming(double xdelta, double ydelta, void *param);
int			error_exit(mlx_t *mlx);
int			invalid_fract(void);

//mandelbrot
void		set_m(void *param);

//julia
void		set_j(void *param);
double		ft_atof(const char *str);

#endif
