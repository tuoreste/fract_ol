/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:52:53 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/18 16:08:34 by otuyishi         ###   ########.fr       */
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
# define RE_START -2
# define RE_END 1
# define IM_START -1
# define IM_END 1
# define MAX_ITER 80

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

typedef struct s_fractol_m
{
	int			x;
	int			y;
	int			m;
	int			color;
	int			pixel_position;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
}			t_fractol_m;

typedef struct s_fractol_j
{
	int			n;
	double		new_real;
	double		new_imag;
	void		*mlx;
	void		*win;
	int			i;
	int			x;
	int			y;
	int			m;
	int			hue;
	int			hue_index;
	int			saturation;
	int			value;
	int			color;
	double		t;
	double		hue_value;
}			t_fractol_j;

//Mandelbrot
int			run_mandelbrot(char *argv);
int			mandelbrot(t_complex c);
//Julia
int			run_julia(char *argv);
int			julia(t_complex c, t_complex z);
t_complex	complex(double real, double imag);
double		map(double value, double start1, double end1, \
			double start2, double end2);
t_color		linear_interpolation(t_color color1, t_color color2, double t);

#endif