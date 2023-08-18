/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:52:15 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/18 16:08:07 by otuyishi         ###   ########.fr       */
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

double	map(double value, double start1, double end1, double start2, double end2)
{
    return start2 + (end2 - start2) * ((value - start1) / (end1 - start1));
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

int	run_julia(char *argv)
{
	t_complex	c;
	t_complex	z0;
	t_color		*colors;
	t_color		the_paint;
	t_color		color1;
	t_color		color2;
	t_fractol_j	j;

	j.i = 0;
	j.mlx = mlx_init();
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
		j.y = 0;
		while (j.y < HEIGHT)
		{
			z0 = complex(RE_START + (j.x / (double)WIDTH) * (RE_END - RE_START),
					IM_START + (j.y / (double)HEIGHT) * (IM_END - IM_START));
			j.m = julia(c, z0);
			j.hue_value = map(j.m, 0, MAX_ITER, 0, 1);
			j.hue_index = (int)(j.hue_value * (MAX_ITER - 1));
			color1 = colors[j.hue_index];
			color2 = colors[j.hue_index + 1];
			j.t = j.hue_value - j.hue_index / (double)(MAX_ITER - 1);
			the_paint = linear_interpolation(color1, color2, j.t);
			j.color = (the_paint.r << 16) | (the_paint.g << 8) | the_paint.b;
			mlx_pixel_put(j.mlx, j.win, j.x, j.y, j.color);
			++j.y;
		}
		++j.x;
	}
	mlx_loop(j.mlx);
	return (0);
}
