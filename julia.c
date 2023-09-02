/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/09/03 01:12:16 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

void	ft_hook1(mlx_key_data_t key_data, void *param)
{
	t_complex	*c;

	c = (t_complex *)param;
	if (key_data.action != MLX_PRESS)
		return ;
	if (key_data.key == MLX_KEY_DOWN)
		c->translate = (c->y_max - c->y_min) * TRANSLATION_FACTOR;
	else if (key_data.key == MLX_KEY_UP)
		c->translate = -(c->y_max - c->y_min) * TRANSLATION_FACTOR;
	else if (key_data.key == MLX_KEY_RIGHT)
		c->translate = (c->x_max - c->x_min) * TRANSLATION_FACTOR;
	else if (key_data.key == MLX_KEY_LEFT)
		c->translate = -(c->x_max - c->x_min) * TRANSLATION_FACTOR;
	if (key_data.key == MLX_KEY_DOWN || key_data.key == MLX_KEY_UP)
	{
		c->y_min += c->translate;
		c->y_max += c->translate;
	}
	else if (key_data.key == MLX_KEY_RIGHT || key_data.key == MLX_KEY_LEFT)
	{
		c->x_min += c->translate;
		c->x_max += c->translate;
	}
	if (key_data.key == MLX_KEY_ESCAPE)
		exit(0);
}

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	t_complex	*c;

	c = (t_complex *)param;
	if (key_data.action != MLX_PRESS)
		return ;
	if (key_data.key == MLX_KEY_DOWN)
		c->c_imag += 0.001;
	else if (key_data.key == MLX_KEY_UP)
		c->c_imag -= 0.001;
	else if (key_data.key == MLX_KEY_RIGHT)
		c->c_real += 0.001;
	else if (key_data.key == MLX_KEY_LEFT)
		c->c_real -= 0.001;
	if (key_data.key == MLX_KEY_ESCAPE)
		exit(0);
	ft_hook1(key_data, param);
}

void	x(t_complex *c)
{
	c->x = 0;
	while (++c->x < W)
	{
		c->x_min = 1.5 * (c->x - W / 2) / (0.5 * c->zoom * W);
		c->x_max = (c->y - H / 2) / (0.5 * c->zoom * H);
		c->iter = 0;
		while (c->iter < MAX_ITER && (c->x_min * c->x_min + c->x_max
				* c->x_max) <= 4)
		{
			c->y_min = c->x_min;
			c->y_max = c->x_max;
			c->x_min = c->y_min * c->y_min - c->y_max * c->y_max + c->c_real;
			c->x_max = 2 * c->y_min * c->y_max + c->c_imag;
			c->iter++;
		}
		mlx_put_pixel(c->image, c->x, c->y, (ft_pixel(c->iter % 300, c->iter
					% 270, c->iter % 270, 225)));
	}
}

void	set_j(void *param)
{
	t_complex	*c;

	c = (t_complex *)param;
	c->y = 0;
	while (++c->y < H)
	{
		x(c);
	}
}
