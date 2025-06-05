/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:22:21 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/06 00:34:39 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Error with malloc!\n");
	exit(EXIT_FAILURE);
}

static char	*get_win_title(int type)
{
	if (type == MANDELBROT)
		return ("Mandelbrot");
	else
		return ("Julia");
}

void	init_fractal(t_fractal *frac, char **av)
{
	if (frac->type == JULIA_WITH_PARAMS)
	{
		frac->ju_re = fr_atod(av[2]);
		frac->ju_im = fr_atod(av[3]);
	}
	else if (frac->type == JULIA)
	{
		frac->ju_re = -0.8;
		frac->ju_im = 0.156;
	}
	frac->zoom = 1.0;
	frac->off_x = 0;
	frac->off_y = 0;
}

void	init_graphics(t_fractal *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		malloc_error();
	frac->mlx_win = mlx_new_window(frac->mlx, WIDTH, HEIGHT,
			get_win_title(frac->type));
	if (!frac->mlx_win)
		malloc_error();
	frac->img.img_ptr = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img.img_ptr)
	{
		mlx_destroy_window(frac->mlx, frac->mlx_win);
		malloc_error();
	}
	frac->img.pix_ptr = mlx_get_data_addr(frac->img.img_ptr, &frac->img.bpp,
			&frac->img.line_len, &frac->img.endian);
	if (!frac->img.pix_ptr)
	{
		mlx_destroy_window(frac->mlx, frac->mlx_win);
		malloc_error();
	}
}
