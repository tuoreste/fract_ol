/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:52:15 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/20 17:15:01 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	linear_interpolation(t_color color1, t_color color2, double t)
{
	t_color	result;

	result.r = color1.r * (1 - t) + color2.r * t;
	result.g = color1.g * (1 - t) + color2.g * t;
	result.b = color1.b * (1 - t) + color2.b * t;
	return (result);
}

t_complex	complex(double real, double imag)
{
	t_complex	result;

	result.real = real;
	result.imag = imag;
	return (result);
}

int	julia(t_complex c, t_complex z)
{
	t_complex	z_temp;
	t_fractol_j	j;

	z_temp = z;
	j.n = 0;
	while (j.n < MAX_ITER)
	{
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
		j.new_real = z.real * z.real - z.imag * z.imag + c.real;
		j.new_imag = 2 * z.real * z.imag + c.imag;
		z.real = j.new_real;
		z.imag = j.new_imag;
		++j.n;
	}
	return (j.n);
}

void	height_controller(int y)
{
	t_complex	c;
	t_fractol_j	j;
	t_complex	z0;
	t_coloring	col;

	y = 0;
	while (y < HEIGHT)
	{
		z0 = complex(RE_START + (j.x / (double)WIDTH) * (RE_END - RE_START),
				IM_START + (y / (double)HEIGHT) * (IM_END - IM_START));
		j.m = julia(c, z0);
		j.hue_value = 0 + (1 - 0) * ((j.m - 0) / (MAX_ITER - 0));
		j.hue_index = (int)(j.hue_value * (MAX_ITER - 1));
		col.color1 = col.colors[j.hue_index];
		col.color2 = col.colors[j.hue_index + 1];
		j.t = j.hue_value - j.hue_index / (double)(MAX_ITER - 1);
		col.paint = linear_interpolation(col.color1, col.color2, j.t);
		j.color = (col.paint.r << 16) | (col.paint.g << 8) | col.paint.b;
		mlx_pixel_put(j.mlx, j.win, j.x, y, j.color);
		++y;
	}
}

int	run_julia(char *argv)
{
	t_complex	c;
	t_color		*colors;
	t_fractol_j	j;
	int			y;

	j.i = 0;
	j.mlx = mlx_init(WIDTH, HEIGHT, "julia", 1);
	j.win = mlx_new_window(j.mlx, WIDTH, HEIGHT, argv);
	c = complex(0.285, 0.01);
	colors = malloc(MAX_ITER * sizeof(t_color));
	while (j.i < MAX_ITER)
	{
		j.t = (double)j.i / (MAX_ITER - 1);
		colors[j.i].r = (int)(255 * j.t);
		colors[j.i].g = (int)(255 * j.t);
		colors[j.i].b = (int)(255 * j.t);
	}
	j.x = 0;
	while (j.x < WIDTH)
	{
		height_controller(y);
		++j.x;
	}
	mlx_loop(j.mlx);
	return (0);
}
