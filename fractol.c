/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:52:33 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/26 22:54:50 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0
			|| ft_strcmp(argv[1], "mandelbrot") == 0
			|| ft_strcmp(argv[1], "M") == 0 || ft_strcmp(argv[1], "m") == 0)
			run_mandelbrot("Mandelbrot");
		// else if ((ft_strcmp(argv[1], "Julia") == 0
		// 		|| ft_strcmp(argv[1], "julia") == 0
		// 		|| ft_strcmp(argv[1], "J") == 0
		// 		|| ft_strcmp(argv[1], "j")) == 0 && argc == 4)
		// {
		// 	run_julia("Julia", argv[2], argv[3]);
		// }
		// else
		// 	write(1, "Invalid Fractal\n", 16);
	}
	else
	{
		write(1, "Invalid Fractol\n", 16);
		return (EXIT_FAILURE);
	}
	return (0);
}
