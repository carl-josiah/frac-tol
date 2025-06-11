/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:01:45 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/11 11:57:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_fractal *frac)
{
	(void) x;
	(void) y;
	if (button == MOUSE_WHEEL_UP)
		frac->zoom *= 1.1;
	else if (button == MOUSE_WHEEL_DOWN)
		frac->zoom /= 1.1;
	render_fractal(frac);
	mlx_put_image_to_window(frac->mlx, frac->mlx_win,
		frac->img.img_ptr, 0, 0);
	return (0);
}

int	handle_close(t_fractal *frac)
{
	if (frac->img.img_ptr)
		mlx_destroy_image(frac->mlx, frac->img.img_ptr);
	if (frac->mlx_win)
		mlx_destroy_window(frac->mlx, frac->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_up_down(int keycode, t_fractal *frac)
{
	int	need_render;

	need_render = 0;
	if (keycode == UP_ARROW)
	{
		frac->off_y += 0.1 / frac->zoom;
		need_render = 1;
	}
	else if (keycode == DOWN_ARROW)
	{
		frac->off_y -= 0.1 / frac->zoom;
		need_render = 1;
	}
	if (need_render)
	{
		render_fractal(frac);
		mlx_put_image_to_window(frac->mlx,
			frac->mlx_win, frac->img.img_ptr, 0, 0);
	}
	return (0);
}

int	handle_left_right(int keycode, t_fractal *frac)
{
	int	need_render;

	need_render = 0;
	if (keycode == LEFT_ARROW)
	{
		frac->off_x -= 0.1 / frac->zoom;
		need_render = 1;
	}
	else if (keycode == RIGHT_ARROW)
	{
		frac->off_x += 0.1 / frac->zoom;
		need_render = 1;
	}
	if (need_render)
	{
		render_fractal(frac);
		mlx_put_image_to_window(frac->mlx, frac->mlx_win,
			frac->img.img_ptr, 0, 0);
	}
	return (0);
}

int	handle_key(int keycode, t_fractal *frac)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		handle_left_right(keycode, frac);
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW)
		handle_up_down(keycode, frac);
	return (0);
}
