/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:13:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/09/03 16:02:46 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_exit(mlx_t *mlx)
{
	mlx_close_window(mlx);
	mlx_strerror(mlx_errno);
	return (EXIT_FAILURE);
}

void	zooming(double xdelta, double ydelta, void *param)
{
	t_complex	*c;
	double		x_factor;
	double		y_factor;

	c = (t_complex *)param;
	x_factor = (c->x_max - c->x_min) * ZOOM_FACTOR;
	y_factor = (c->y_max - c->y_min) * ZOOM_FACTOR;
	xdelta = 0;
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
