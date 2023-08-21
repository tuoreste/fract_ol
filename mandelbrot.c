/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:52:05 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/21 09:26:21 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c)
{
	int			n;
	t_complex	z;
	t_complex	temp;

	z.real = 0;
	z.imag = 0;
	n = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && n < MAX_ITER)
	{
		temp.real = z.real;
		temp.imag = z.imag;
		z.real = temp.real * temp.real - temp.imag * temp.imag + c.real;
		z.imag = 2 * temp.real * temp.imag + c.imag;
		n++;
	}
	return (n);
}

void	height_controler(int x)
{
	t_complex	c;
	t_fractol_m	m;
	int			y;

	y = 0;
	while (m.y < HEIGHT)
	{
		c.real = RE_START + ((double)x / WIDTH) * (RE_END - RE_START);
		c.imag = IM_START + ((double)y / HEIGHT) * (IM_END - IM_START);
		m.m = mandelbrot(c);
		m.color = 255 - (int)(((double)m.m / MAX_ITER) * 255);
		m.pixel_position = (y * WIDTH + x) * 4;
		m.img_data[m.pixel_position] = m.color;
		m.img_data[m.pixel_position + 1] = m.color;
		m.img_data[m.pixel_position + 2] = m.color;
		y++;
	}
}

int	run_mandelbrot(char *argv)
{
	t_complex	c;
	t_fractol_m	m;
	t_fractol_m	*mt;
	int			x;

	x = 0;
	m.mlx_ptr = mlx_init(WIDTH, HEIGHT, "MLX42", 1);
	mt = (t_fractol_m *)malloc(sizeof(t_fractol_m));
	if (!m.mlx_ptr)
	{
		mlx
	}
	m.img_ptr = mlx_new_image(m.mlx_ptr, WIDTH, HEIGHT);
	m.img_data = mlx_get_data_addr(m.img_ptr, NULL, NULL, NULL);
	while (x < WIDTH)
	{
		height_controler(x);
		m.x++;
	}
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	mlx_loop(m.mlx_ptr);
	return (0);
}
