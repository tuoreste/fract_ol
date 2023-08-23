/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:52:33 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/22 16:16:35 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") || ft_strcmp(argv[1], "mandelbrot")
			|| ft_strcmp(argv[1], "M") || ft_strcmp(argv[1], "m"))
			run_mandelbrot(argc, argv);
		else if ((ft_strcmp(argv[1], "Julia") || ft_strcmp(argv[1], "julia")
			|| ft_strcmp(argv[1], "J") || ft_strcmp(argv[1], "j")) && argc == 4)
			//run_julia(argc, argv);
			printf("julia is ready");
		else
			write(1, "Invalid Fractal\n", 16);
	}
	else
	{
		write(1, "Invalid Fractol\n", 16);
		return (EXIT_FAILURE);
	}
	return (0);
}
