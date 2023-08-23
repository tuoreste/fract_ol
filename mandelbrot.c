/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:52:05 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/22 16:40:27 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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

void	zooming(double x_move, double y_move, void *var)
{
	t_fractol_m	*mt;
	mlx_t		*mlx_ptr;
	double		third_d;

	mt = (t_fractol_m *)var;
	mlx_ptr = (mlx_t *)var;
	third_d = 0.1;
	x_move = 0;
	if (y_move > 0)
	{
		mt->x_base += (mt->x_roof - mt->x_base) * third_d;
		mt->x_roof -= (mt->x_roof - mt->x_base) * third_d;
		mt->y_base += (mt->y_roof - mt->y_base) * third_d;
		mt->y_base -= (mt->y_roof - mt->y_base) * third_d;
	}
	else if (y_move < 0)
	{
		mt->x_base -= (mt->x_roof - mt->x_base) * third_d;
		mt->x_roof += (mt->x_roof - mt->x_base) * third_d;
		mt->y_base -= (mt->y_roof - mt->y_base) * third_d;
		mt->y_base += (mt->y_roof - mt->y_base) * third_d;
	}
	mt->drawer = 1;
}

void	grid_controller()
{
	t_complex	c;
	t_fractol_m	m;

	m.x = 0;
	while (m.x < WIDTH)
	{
		m.y = 0;
		while (m.y < HEIGHT)
		{
			c.real = RE_START + ((double)m.x / WIDTH) * (RE_END - RE_START);
			c.imag = IM_START + ((double)m.y / HEIGHT) * (IM_END - IM_START);
			m.m = mandelbrot(c);
			m.color = 255 - (int)(((double)m.m / MAX_ITER) * 255);
			m.pixel_position = (m.y * WIDTH + m.x) * 4;
			m.img_data[m.pixel_position] = m.color;
			m.img_data[m.pixel_position + 1] = m.color;
			m.img_data[m.pixel_position + 2] = m.color;
			m.y++;
		}
		m.x++;
	}

	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	mlx_loop(m.mlx_ptr);
}

void	up_down(mlx_key_data_t key_data, t_fractol_m *mt)
{
	if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
	{
		mt->y_base += (mt->y_roof - mt->y_base) * -0.1;
		mt->y_roof += (mt->y_roof - mt->y_base) * -0.1;
	}
	if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
	{
		mt->y_base -= (mt->y_roof - mt->y_base) * -0.1;
		mt->y_roof -= (mt->y_roof - mt->y_base) * -0.1;
	}
}

void	left_right(mlx_key_data_t key_data, t_fractol_m *mt)
{
	if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
	{
		mt->x_base += (mt->x_roof - mt->x_base) * -0.1;
		mt->x_roof += (mt->x_roof - mt->x_base) * -0.1;
	}
	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
	{
		mt->x_base -= (mt->x_roof - mt->x_base) * -0.1;
		mt->x_roof -= (mt->x_roof - mt->x_base) * -0.1;
	}
}

void	m_hook(mlx_key_data_t key_data, void *var)
{
	t_fractol_m	*mt;

	mt = (t_fractol_m *)var;
	up_down(key_data, mt);
	left_right(key_data, mt);
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		return (exit(0));
	mt -> drawer = 1;
}

void	action(int argc, char argv, t_fractol_m *mlx_ptr, t_fractol_m *mt)
{
	mlx_scroll_hook(mlx_ptr, zooming, mt);
	mt -> drawer = 1;
	mt -> x_base = -2.5;
	mt -> x_roof = 1.5;
	mt -> y_base = -1.5;
	mt -> y_roof = 1.5;
	mlx_loop_hook(mlx_ptr, mandelbrot, mt);
	mlx_key_hook(mlx_ptr, m_hook, mt);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
	return (EXIT_SUCCESS);
}

void	imaging(int argc, char argv, t_fractol_m *mlx_ptr, t_fractol_m *mt)
{
	t_fractol_m	m;

	m.img_ptr = mlx_new_image(m.mlx_ptr, WIDTH, HEIGHT);
	if (!m.img_ptr)
	{
		mlx_close_window(m.mlx_ptr);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(m.mlx_ptr, m.img_ptr, 0, 0) == -1)
	{
		mlx_close_window(m.mlx_ptr);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	action(argc, argv, mlx_ptr, mt);
}

int	run_mandelbrot(int argc, char **argv)
{
	t_fractol_m	m;
	t_fractol_m	*mt;

	m.mlx_ptr = mlx_init(WIDTH, HEIGHT, "MLX42", 1);
	mt = (t_fractol_m *)malloc(sizeof(t_fractol_m));
	if (!mt)
		return (EXIT_FAILURE);
	if (!m.mlx_ptr)
	{
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	imaging(argc, argv, m.mlx_ptr, mt);
	free (mt);
}
