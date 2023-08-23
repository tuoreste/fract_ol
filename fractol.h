/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:52:53 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/22 11:37:22 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define MAX_ITER 80
# define WIDTH 600
# define HEIGHT 400
# define RE_START -2.5
# define RE_END 1.0
# define IM_START -1.5
# define IM_END 1.5
# define ZOOM_FACTOR 2

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_col
{
	t_color		*colors;
	t_color		color1;
	t_color		color2;
	t_color		paint;
}				t_coloring;

typedef struct s_fractol_m
{
	int			x;
	int			y;
	int			m;
	double		x_base;
	double		x_roof;
	double		y_base;
	double		y_roof;
	int			color;
	int			pixel_position;
	int			drawer;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
}				t_fractol_m;

typedef struct s_fractol_j
{
	int			n;
	double		new_real;
	double		new_imag;
	void		*mlx;
	void		*win;
	int			i;
	int			x;
	int			m;
	int			hue;
	int			hue_index;
	int			saturation;
	int			value;
	int			color;
	double		t;
	double		hue_value;
}			t_fractol_j;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
}			t_data;

int			ft_strcmp(char *s1, char *s2);
//Mandelbrot
int			run_mandelbrot(int argc, char **argv);
int			mandelbrot(t_complex c);
//Julia
int			run_julia(char *argv);
int			julia(t_complex c, t_complex z);
t_complex	complex(double real, double imag);
t_color		linear_interpolation(t_color color1, t_color color2, double t);

#endif
