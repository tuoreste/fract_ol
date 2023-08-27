/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57:55 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/27 20:08:36 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	equation_m(t_complex *c, int x, int y)
{
	c->real = c->x_min + (double)x / c->image->width * (c->x_max - c->x_min);
	c->imag = c->y_min + (double)y / c->image->height * (c->y_max - c->y_min);
	c->c_real = c->real;
	c->c_imag = c->imag;
	c->iter = 0;
	c->z_real = 0.0;
	c->z_imag = 0.0;
}

void	refresh_figs(t_complex *c)
{
	double	temp;

	temp = c->z_real * c->z_real - c->z_imag * c->z_imag + c->c_real;
	c->z_imag = 2.0 * c->z_real * c->z_imag + c->c_imag;
	c->z_real = temp;
	c->iter++;
}

void	set_m(void *param)
{
	uint32_t	x;
	uint32_t	y;
	t_complex	*c;

	c = (t_complex *)param;
	y = 0;
	c->x_min = -2.5;
	c->x_max = 1.0;
	c->y_min = -1.5;
	c->y_max = 1.5;
	while (++y < c->image->height)
	{
		x = 0;
		while (++x < c->image->width)
		{
			equation_m(c, x, y);
			while (c->iter < MAX_ITER && c->z_real * c->z_real + c->z_imag
				* c->z_imag <= 4.0)
				refresh_figs(c);
			mlx_put_pixel(c->image, x, y, (ft_pixel(c->iter % 210, \
					c->iter % 210, c->iter % 210, 255)));
		}
	}
}
