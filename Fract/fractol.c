/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:13:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/27 22:17:51 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_exit(mlx_t *mlx)
{
	mlx_close_window(mlx);
	mlx_strerror(mlx_errno);
	return (EXIT_FAILURE);
}

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	t_complex	*c;

	c = (t_complex *)param;
	if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
	{
		c->y_min += (c->y_max - c->y_min) * -0.1;
		c->y_max += (c->y_max - c->y_min) * -0.1;
	}
	if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
	{
		c->y_min -= (c->y_max - c->y_min) * -0.1;
		c->y_max -= (c->y_max - c->y_min) * -0.1;
	}
	if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
	{
		c->x_min += (c->x_max - c->x_min) * -0.1;
		c->x_max += (c->x_max - c->x_min) * -0.1;
	}
	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
	{
		c->x_min -= (c->x_max - c->x_min) * -0.1;
		c->x_max -= (c->x_max - c->x_min) * -0.1;
	}
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		return (exit(0));
}

int32_t	main(int32_t argc, const char **argv)
{
	mlx_t		*mlx;
	t_complex	*c;

	c = (t_complex *)malloc(sizeof(t_complex));
	mlx = mlx_init(W, H, "MLX42", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	c->image = mlx_new_image(mlx, H, W);
	if (!(c->image))
		error_exit(mlx);
	if (mlx_image_to_window(mlx, c->image, 0, 0) == -1)
		error_exit(mlx);
	mlx_loop_hook(mlx, set_m, c);
	mlx_key_hook(mlx, ft_hook, c);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
