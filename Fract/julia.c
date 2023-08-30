/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/30 14:26:20 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_exit(mlx_t *mlx)
{
	mlx_close_window(mlx);
	mlx_strerror(mlx_errno);
	return (EXIT_FAILURE);
}

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

void	x(int y, t_complex *c)
{
	int			x;

	x = 0;
	while (++x < W)
	{
		c->x_min = 1.5 * (x - W / 2) / \
		(0.5 * W);
		c->x_max = (y - H / 2) / \
		(0.5 * H);
		c->iter = 0;
		while (c->iter < MAX_ITER && \
			(c->x_min * c->x_min + c->x_max * c->x_max) <= 4)
		{
			c->y_min = c->x_min;
			c->y_max = c->x_max;
			c->x_min = c->y_min * c->y_min - c->y_max \
			* c->y_max + c->c_real;
			c->x_max = 2 * c->y_min * c->y_max + c->c_imag;
			c->iter++;
		}
		mlx_put_pixel(c->image, x, y, (ft_pixel(c->iter % 300, \
				c->iter % 270, c->iter % 270, 225)));
	}
}

void	set_j(void *param)
{
	t_complex	*c;
	int			y;

	c = (t_complex *)param;
	y = 0;
	while (++y < H)
	{
		x(y, c);
	}
}
