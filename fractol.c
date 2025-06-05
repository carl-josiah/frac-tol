/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:39:17 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/06 00:16:13 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	write_error(void)
{
	char	*error_message_1;
	char	*error_message_2;
	char	*error_message_3;

	error_message_1 = "Correct usage: ./fractal <fractal name>\n";
	error_message_2 = "Available fractals: mandelbrot | ";
	error_message_3 = "julia | julia <num1> <num2>\n";
	write(2, error_message_1, fr_strlen(error_message_1));
	write(2, error_message_2, fr_strlen(error_message_2));
	write(2, error_message_3, fr_strlen(error_message_3));
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	frac;

	if (ac < 2)
		write_error();
	else if (has_error(&frac, ac, av))
		write_error();
	init_fractal(&frac, av);
	init_graphics(&frac);
	mlx_key_hook(frac.mlx_win, handle_key, &frac);
	mlx_mouse_hook(frac.mlx_win, handle_mouse, &frac);
	mlx_hook(frac.mlx_win, DESTROY_NOTIFY, NO_MASK, handle_close, &frac);
	render_fractal(&frac);
	mlx_put_image_to_window(frac.mlx, frac.mlx_win, frac.img.img_ptr,
		0, 0);
	mlx_loop(frac.mlx);
	return (EXIT_SUCCESS);
}
