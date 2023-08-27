/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:31:12 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/27 20:08:44 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"

# define MAX_ITER 500
# define W 1080
# define H 1080

typedef struct s_complex
{
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		real;
	double		imag;
	double		c_real;
	double		c_imag;
	int			iter;
	double		z_real;
	double		z_imag;
	double		temp;
	uint32_t	color;
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			should_draw;
}				t_complex;

int	ft_strcmp(char *s1, char *s2);

//mandelbrot
void	set_m(void *param);

//julia
t_complex	addition(t_complex a, t_complex b);
t_complex	sqr(t_complex a);
double		sqrt(double a);
double		mod(t_complex a);
t_complex	mappings(int w, int h, double r, int x, int y);
void		j_set(int w, int h, t_complex c, double r, int n);
double		ft_atodigit(const char **str);
double		ft_atof(const char **str);

#endif
