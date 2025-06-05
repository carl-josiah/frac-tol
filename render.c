/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:20:21 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/06 00:40:15 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot_iterations(double re, double im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	temp;

	i = 0;
	z_re = 0.0;
	z_im = 0.0;
	while (i < MAX_ITER)
	{
		temp = z_re;
		if (((z_re * z_re) + (z_im * z_im)) > 4)
			break ;
		z_re = (temp * temp) - (z_im * z_im) + re;
		z_im = (2 * temp) * z_im + im;
		i++;
	}
	return (i);
}

static int	julia_iterations(double z_re, double z_im, double c_re, double c_im)
{
	int		i;
	double	temp;

	i = 0;
	while (i < MAX_ITER)
	{
		temp = z_re;
		if (((z_re * z_re) + (z_im * z_im)) > 4)
			break ;
		z_re = (temp * temp) - (z_im * z_im) + c_re;
		z_im = (2 * temp) * z_im + c_im;
		i++;
	}
	return (i);
}

static int	get_color(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
		return (0x000000);
	r = (iter * 9) % 256;
	g = (iter * 15) % 256;
	b = (iter * 20) % 256;
	return ((r << 16) | (g << 8) | b);
}

static int	pixel_to_iter(int x, int y, t_fractal *frac)
{
	int		iter;
	double	re;
	double	im;

	iter = 0;
	if (frac->type == MANDELBROT)
	{
		re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * frac->zoom) - 0.5 + frac->off_x;
		im = -(y - HEIGHT / 2.0) * 4.0 / (HEIGHT * frac->zoom) + frac->off_y;
		iter = mandelbrot_iterations(re, im);
	}
	else if (frac->type == JULIA || frac->type == JULIA_WITH_PARAMS)
	{
		re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * frac->zoom) + frac->off_x;
		im = -(y - HEIGHT / 2.0) * 4.0 / (HEIGHT * frac->zoom) + frac->off_y;
		iter = julia_iterations(re, im, frac->ju_re, frac->ju_im);
	}
	return (iter);
}

void	render_fractal(t_fractal *frac)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_color(pixel_to_iter(x, y, frac));
			mlx_put_pixel(&frac->img, x, y, color);
			x++;
		}
		y++;
	}
}
