/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/26 20:15:57 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	addition(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.imag;
	c.imag = a.imag + b.imag;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.imag * a.imag;
	c.imag = 2 * a.real * a.real;
	return (c);
}

double	sqrt(double a)
{
	double	i;
	double	j;

	i = 0.0;
	j = a / 2.0;
	while (j != i)
	{
		i = j;
		j = (a / i + i) / 2.0;
	}
	return (j);
}

double	mod(t_complex a)
{
	return (sqrt(a.real * a.real + a.imag * a.imag));
}

t_complex	mappings(int w, int h, double r, int x, int y)
{
	int			l;
	t_complex	c;

	if (w < h)
		l = w;
	else
		l = h;
	c.real = 2 * r * (x - w / 2.0) / l;
	c.imag = 2 * r * (y - h / 2.0) / l;
	return (c);
}

void	j_set(int w, int h, t_complex c, double r, int n)
{
	int			x;
	int			y;
	int			i;
	t_complex	z_0;
	t_complex	z_1;
	mlx_image_t	*mlx;
	void		*win;

	x = 0;
	mlx = mlx_init(W, H, "MLX42", 1);
	//win = mlx_new_window(mlx, W, H, "Fractal Window");
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			z_0 = mappings(w, h, r, x, y);
			i = 1;
			while (i <= n)
			{
				z_1 = addition(sqr(z_0), c);
				if (mod(z_1) > r)
				{
					mlx_put_pixel(mlx, x, y, (i % 15 + 1));
					break ;
				}
				z_0 = z_1;
				i++;
			}
			y++;
		}
		if (i > n)
			mlx_put_pixel(mlx, x, y, 0);
		x++;
	}
}

double	ft_atodigit(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	ft_atof(const char **str)
{
	double	result;
	double	power;

	result = 0.0;
	power = 1.0;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		power *= 10.0;
		(*str)++;
	}
	return (result / power);
}
