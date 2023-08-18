/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:52:33 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/18 16:34:19 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	else
	{
		if (argv[1] == "Mandelbrot" || argv[1] == "mandelbrot"
			|| argv[1] == "M" || argv[1] == "m")
			run_mandelbrot(argv);
		else if (argv[1] == "Julia" || argv[1] == "julia"
			|| argv[1] == "J" || argv[1] == "j")
			run_julia(argv);
		else
			write(1, "Invalid Fractal\n", 16);
	}
	return (0);
}
