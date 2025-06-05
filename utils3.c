/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:03:58 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/06 00:01:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(int *)(img->pix_ptr + offset) = color;
}
