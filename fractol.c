/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:13:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/31 00:00:37 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	zooming(double xdelta, double ydelta, void *param)
// {
// 	t_complex	*c;

// 	c = (t_complex *)param;
// 	if (ydelta > 0)
// 	{
// 		c->x_min += (c->x_max - c->x_min) * ZOOM_FACTOR;
// 		c->x_max -= (c->x_max - c->x_min) * ZOOM_FACTOR;
// 		c->y_min += (c->y_max - c->y_min) * ZOOM_FACTOR;
// 		c->y_min -= (c->y_max - c->y_min) * ZOOM_FACTOR;
// 		c->zoom += 0.1;
// 	}
// 	else if (ydelta < 0)
// 	{
// 		c->x_min -= (c->x_max - c->x_min) * ZOOM_FACTOR;
// 		c->x_max += (c->x_max - c->x_min) * ZOOM_FACTOR;
// 		c->y_min -= (c->y_max - c->y_min) * ZOOM_FACTOR;
// 		c->y_min += (c->y_max - c->y_min) * ZOOM_FACTOR;
// 		c->zoom -= 0.1;
// 	}
// }

void	zooming(double xdelta, double ydelta, void *param)
{
	t_complex	*c;
	double		x_factor;
	double		y_factor;

	c = (t_complex *)param;
	x_factor = (c->x_max - c->x_min) * ZOOM_FACTOR;
	y_factor = (c->y_max - c->y_min) * ZOOM_FACTOR;
	if (ydelta > 0)
	{
		c->x_min += x_factor;
		c->x_max -= x_factor;
		c->y_min += y_factor;
		c->y_max -= y_factor;
		c->zoom += 0.1;
	}
	else if (ydelta < 0)
	{
		c->x_min -= x_factor;
		c->x_max += x_factor;
		c->y_min -= y_factor;
		c->y_max += y_factor;
		c->zoom -= 0.1;
	}
}

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	t_complex	*c;

	c = (t_complex *)param;
	if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
	{
		c->y_min += (c->y_max - c->y_min) * -0.1;
		c->y_max += (c->y_max - c->y_min) * -0.1;
	}
	else if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
	{
		c->y_min -= (c->y_max - c->y_min) * -0.1;
		c->y_max -= (c->y_max - c->y_min) * -0.1;
	}
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
	{
		c->x_min += (c->x_max - c->x_min) * -0.1;
		c->x_max += (c->x_max - c->x_min) * -0.1;
	}
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
	{
		c->x_min -= (c->x_max - c->x_min) * -0.1;
		c->x_max -= (c->x_max - c->x_min) * -0.1;
	}
	else if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		return (exit(0));
}

void	call_me(mlx_t *mlx, t_complex *c)
{
	mlx_key_hook(mlx, ft_hook, c);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	execution(int argc, char **argv, mlx_t *mlx, t_complex *c)
{
	if (ft_strcmp(argv[1], "m") && argc == 2)
	{
		c->zoom = 1;
		c->x_min = -2.5;
		c->x_max = 1.0;
		c->y_min = -1.5;
		c->y_max = 1.5;
		mlx_loop_hook(mlx, set_m, c);
	}
	else if (ft_strcmp(argv[1], "j") && argc == 4)
	{
		c->zoom = 1;
		c->c_real = ft_atof(argv[2]);
		c->c_imag = ft_atof(argv[3]);
		mlx_loop_hook(mlx, set_j, c);
	}
	else
		return (write(1, "Invalid Fractol\nType 'm' for Mandelbrot\n \
		or      \nType 'j' '-0.52519' '-0.52519' for Julia\n", 92), \
		EXIT_FAILURE);
	call_me(mlx, c);
	return (EXIT_SUCCESS);
}

int32_t	main(int32_t argc, char **argv)
{
	mlx_t		*mlx;
	t_complex	*c;

	if (argc <= 1)
	{
		write(1, "Invalid Fractol\nType 'm' for Mandelbrot\n \
		or      \nType 'j' '-0.52519' '-0.52519' for Julia\n", 92);
		return (EXIT_FAILURE);
	}
	c = (t_complex *)malloc(sizeof(t_complex));
	mlx = mlx_init(W, H, "MLX42", true);
	if (!mlx)
	{
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	c->image = mlx_new_image(mlx, W, H);
	if (!(c->image))
		error_exit(mlx);
	if (mlx_image_to_window(mlx, c->image, 0, 0) == -1)
		error_exit(mlx);
	mlx_scroll_hook(mlx, zooming, c);
	execution(argc, argv, mlx, c);
	free(c);
	return (EXIT_SUCCESS);
}
