/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:52:15 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/26 22:56:08 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"

// t_color	linear_interpolation(t_color color1, t_color color2, double t)
// {
// 	t_color	result;

// 	result.r = color1.r * (1 - t) + color2.r * t;
// 	result.g = color1.g * (1 - t) + color2.g * t;
// 	result.b = color1.b * (1 - t) + color2.b * t;
// 	return (result);
// }

// t_complex	complex(double real, double imag)
// {
// 	t_complex	result;

// 	result.real = real;
// 	result.imag = imag;
// 	return (result);
// }

// int	julia(t_complex c, t_complex z)
// {
// 	t_complex	z_temp;
// 	t_fractol_j	j;

// 	z_temp = z;
// 	j.n = 0;
// 	while (j.n < MAX_ITER)
// 	{
// 		if (z.real * z.real + z.imag * z.imag > 4)
// 			break ;
// 		j.new_real = z.real * z.real - z.imag * z.imag + c.real;
// 		j.new_imag = 2 * z.real * z.imag + c.imag;
// 		z.real = j.new_real;
// 		z.imag = j.new_imag;
// 		++j.n;
// 	}
// 	return (j.n);
// }

// void	zooming_j(double x_move, double y_move, void *var)
// {
// 	t_fractol_j	*jul;
// 	mlx_t		*mlx_ptr;
// 	double		third_d;

// 	jul = (t_fractol_j *)var;
// 	mlx_ptr = (mlx_t *)var;
// 	third_d = 0.1;
// 	x_move = 0;
// 	if (y_move > 0)
// 	{
// 		jul->x_base += (jul->x_roof - jul->x_base) * third_d;
// 		jul->x_roof -= (jul->x_roof - jul->x_base) * third_d;
// 		jul->y_base += (jul->y_roof - jul->y_base) * third_d;
// 		jul->y_base -= (jul->y_roof - jul->y_base) * third_d;
// 	}
// 	else if (y_move < 0)
// 	{
// 		jul->x_base -= (jul->x_roof - jul->x_base) * third_d;
// 		jul->x_roof += (jul->x_roof - jul->x_base) * third_d;
// 		jul->y_base -= (jul->y_roof - jul->y_base) * third_d;
// 		jul->y_base += (jul->y_roof - jul->y_base) * third_d;
// 	}
// 	jul->drawer = 1;
// }

// double	ft_atodigit(const char **str)
// {
// 	double	result;

// 	result = 0.0;
// 	while (**str >= '0' && **str <= '9')
// 	{
// 		result = result * 10.0 + (**str - '0');
// 		(*str)++;
// 	}
// 	return (result);
// }

// double	ft_atofraction(const char **str)
// {
// 	double	result;
// 	double	power;

// 	result = 0.0;
// 	power = 1.0;
// 	(*str)++;
// 	while (**str >= '0' && **str <= '9')
// 	{
// 		result = result * 10.0 + (**str - '0');
// 		power *= 10.0;
// 		(*str)++;
// 	}
// 	return (result / power);
// }

// double	ft_atof(const char *str)
// {
// 	double	result;
// 	double	sign;
// 	int		f;

// 	result = 0.0;
// 	sign = 1.0;
// 	f = 0;
// 	while (*str == ' ' || *str == '\t' || *str == '\n'
// 		|| *str == '\v' || *str == '\f' || *str == '\r')
// 		str++;
// 	if (*str == '-')
// 	{
// 		sign = -1.0;
// 		str++;
// 	}
// 	else if (*str == '+')
// 		str++;
// 	result = ft_atodigit(&str);
// 	if (*str == '.')
// 	{
// 		f = 1;
// 		result += ft_atofraction(&str);
// 	}
// 	return (result * sign);
// }

// void	grid_controller_j(void *param)
// {
// 	t_complex	*c;
// 	t_fractol_j	j;

// 	c = (t_complex *)param;
// 	j.x = 0;
// 	while (j.x < WIDTH)
// 	{
// 		j.y = 0;
// 		while (j.y < HEIGHT)
// 		{
// 			c->real = RE_START + ((double)j.x / WIDTH) * (RE_END - RE_START);
// 			c->imag = IM_START + ((double)j.y / HEIGHT) * (IM_END - IM_START);
// 			j.m = julia(c, j.a);
// 			j.color = 255 - (int)(((double)j.m / MAX_ITER) * 255);
// 			j.pixel_position = (j.y * WIDTH + j.x) * 4;
// 			j.img_data[j.pixel_position] = j.color;
// 			j.img_data[j.pixel_position + 1] = j.color;
// 			j.img_data[j.pixel_position + 2] = j.color;
// 			j.y++;
// 		}
// 		j.x++;
// 	}
// }

// void	action_j(mlx_t *mlx_ptr, t_fractol_j *jul)
// {
// 	mlx_scroll_hook(mlx_ptr, zooming_j, jul);
// 	jul -> drawer = 1;
// 	jul -> x_base = -2.5;
// 	jul -> x_roof = 1.5;
// 	jul -> y_base = -1.5;
// 	jul -> y_roof = 1.5;
// 	mlx_loop_hook(mlx_ptr, grid_controller_j, jul);
// 	mlx_key_hook(mlx_ptr, m_hook, jul);
// 	mlx_loop(mlx_ptr);
// 	mlx_terminate(mlx_ptr);
// 	return ;
// }

// void	imaging_j(mlx_t *mlx_ptr, t_fractol_j *jul)
// {
// 	t_fractol_j	j;

// 	j.img_ptr = mlx_new_image(j.mlx_ptr, WIDTH, HEIGHT);
// 	if (!j.img_ptr)
// 	{
// 		mlx_close_window(j.mlx_ptr);
// 		mlx_strerror(mlx_errno);
// 		return ;
// 	}
// 	if (mlx_image_to_window(j.mlx_ptr, j.img_ptr, 0, 0) == -1)
// 	{
// 		mlx_close_window(j.mlx_ptr);
// 		mlx_strerror(mlx_errno);
// 		return ;
// 	}
// 	action_j(mlx_ptr, jul);
// }

// void	run_julia(char *str, char *str_two, char *str_three)
// {
// 	t_fractol_j	j;
// 	t_fractol_j	*jul;

// 	jul = (t_fractol_j *)malloc(sizeof(t_fractol_j));
// 	jul->mlx_ptr = mlx_init(WIDTH, HEIGHT, "MLX42", 1);
// 	if (!jul)
// 		return ;
// 	if (!j.mlx_ptr)
// 	{
// 		mlx_strerror(mlx_errno);
// 		return ;
// 	}
// 	if (ft_strcmp(str, "Julia") == 0)
// 		imaging_j(j.mlx_ptr, jul);
// 	free (jul);
// }
