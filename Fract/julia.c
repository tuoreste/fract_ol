/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/29 16:02:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_j(void *param)
{
	t_complex	*c;
	int			x;
	int			y;

	c = (t_complex *)param;
	y = 0;
	while (++y < H)
	{
		x = 0;
		while (++x < W)
		{
			c->new_real = 1.5 * (x - W / 2) / \
			(0.5 * c->zoom * W) + c->move_x;
			c->new_imag = (y - H / 2) / \
			(0.5 * c->zoom * H) + c->move_y;
			c->iter = 0;
			while (c->iter < MAX_ITER && \
				(c->new_real * c->new_real + c->new_imag * c->new_imag) <= 4)
			{
				c->old_real = c->new_real;
				c->old_imag = c->new_imag;
				c->new_real = c->old_real * c->old_real - c->old_imag \
				* c->old_imag + c->c_real;
				c->new_imag = 2 * c->old_real * c->old_imag + c->c_imag;
				c->iter++;
			}
			mlx_put_pixel(c->image, x, y, (ft_pixel(c->iter % 300, \
					c->iter % 270, c->iter % 270, 225)));
		}
	}
}
