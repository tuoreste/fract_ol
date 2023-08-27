/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:52:53 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/26 22:53:48 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "lib/MLX42/include/MLX42/MLX42.h"

# define MAX_ITER 80
# define WIDTH 600
# define HEIGHT 400
# define RE_START -2.5
# define RE_END 1.0
# define IM_START -1.5
# define IM_END 1.5
# define ZOOM_FACTOR 2

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_col
{
	t_color		*colors;
	t_color		color1;
	t_color		color2;
	t_color		paint;
}				t_coloring;

typedef struct s_fractol_m
{
	int			x;
	int			y;
	int			m;
	double		x_base;
	double		x_roof;
	double		y_base;
	double		y_roof;
	int			color;
	int			pixel_position;
	int			drawer;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
}				t_fractol_m;

typedef struct s_fractol_j
{
	int			n;
	double		new_real;
	double		new_imag;
	int			color;
	void		*mlx_ptr;
	void		*win;
	int			drawer;
	double		x_base;
	double		x_roof;
	double		y_base;
	double		y_roof;
	int			i;
	int			x;
	int			y;
	int			pixel_position;
	char		*img_data;
	int			m;
	int			hue;
	int			hue_index;
	int			saturation;
	void		*img_ptr;
	int			value;
	double		t;
	double		hue_value;
	float		a;
	float		b;
}			t_fractol_j;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
}			t_data;

//Mandelbrot
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int		mandelbrot(t_complex *c);
void	grid_controller_m(void *mt);
void	zooming_m(double x_move, double y_move, void *var);
void	up_down(mlx_key_data_t key_data, t_fractol_m *mt);
void	left_right(mlx_key_data_t key_data, t_fractol_m *mt);
void	m_hook(mlx_key_data_t key_data, void *var);
void	action_m(mlx_t *mlx_ptr, t_fractol_m *mt);
void	imaging_m(mlx_t *mlx_ptr, t_fractol_m *mt);
void	run_mandelbrot(char *str);
int		ft_strcmp(char *s1, char *s2);

//Julia
t_color		linear_interpolation(t_color color1, t_color color2, double t);
t_complex	complex(double real, double imag);
int			julia(t_complex c, t_complex z);
void		zooming_j(double x_move, double y_move, void *var);
void		grid_controller_j(void *param);
void		action_j(mlx_t *mlx_ptr, t_fractol_j *jul);
void		imaging_j(mlx_t *mlx_ptr, t_fractol_j *jul);
void		run_julia(char *str, char *str_two, char *str_three);

#endif
