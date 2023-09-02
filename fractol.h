/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:31:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/09/03 01:13:49 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ZOOM_FACTOR 0.1
# define TRANSLATION_FACTOR 0.1
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
	int			draw;
	double		z_real;
	double		z_imag;
	uint32_t	color;
	mlx_image_t	*image;
	mlx_t		*mlx;
	double		zoom;
	double		translate;

}				t_complex;

// common
int				ft_strcmp(char *s1, char *s2);
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int				execution(int argc, char **argv, mlx_t *mlx, t_complex *c);
void			zooming(double xdelta, double ydelta, void *param);
int				error_exit(mlx_t *mlx);
void			ft_hook1(mlx_key_data_t key_data, void *param);
void			ft_hook(mlx_key_data_t key_data, void *param);

// mandelbrot
void			set_m(void *param);

// julia
void			set_j(void *param);
double			ft_atof(const char *str);

// utils
double			ft_atof(const char *str);
double			convert_to_float(const char *str);
int				is_valid_input(const char *str);
double			ft_atofraction(const char **str);
double			ft_atodigit(const char **str);
int				ft_isdigit(int c);
int				ft_isspace(int c);

#endif
