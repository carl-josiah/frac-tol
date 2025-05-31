/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:39:17 by ccastro           #+#    #+#             */
/*   Updated: 2025/05/31 17:02:35 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	write_error(void)
{
	write(2, "Usage: ./fractal <fractal name>\n", 33);
	write(2, "Available fractals: mandelbrot | julia\n", 40);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!fr_strncmp(av[1], "mandelbrot", 10))
		{
			write(1, "mandelbrot\n", 11);
		}
		else if (!fr_strncmp(av[1], "julia", 5))
		{
			write(1, "julia\n", 6);
		}
	}
	else
		write_error();
	exit (EXIT_SUCCESS);
}
