/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:40:00 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/11 12:06:06 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# ifdef __APPLE__
#  include "minilibx_opengl_20191021/mlx.h"
# else
#  include "minilibx-linux/mlx.h"
# endif

# define WIDTH 400
# define HEIGHT 400
# define DEFAULT_AC 2
# define JULIA_AC 4
# define MANDELBROT 1
# define JULIA 2
# define JULIA_WITH_PARAMS 3
# define MAX_ITER 100

# define ESC 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define DESTROY_NOTIFY 17
# define NO_MASK 0
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_frac
{
	int		type;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	double	ju_re;
	double	ju_im;
	double	zoom;
	double	off_x;
	double	off_y;
}			t_fractal;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

int		fr_strncmp(const char *s1, const char *s2, size_t n);
size_t	fr_strlen(const char *str);
void	fr_putstr(const char *str);
double	fr_atod(const char *str);

int		is_delim(char c);
int		is_digit(char c);
int		is_sign(char c);

int		which_fractal(int ac, char *fractal);
int		has_error(t_fractal *frac, int ac, char **av);

void	init_fractal(t_fractal *frac, char **av);
void	init_graphics(t_fractal *frac);
void	render_fractal(t_fractal *frac);

int		handle_key(int keycode, t_fractal *frac);
int		handle_mouse(int button, int x, int y, t_fractal *frac);
int		handle_close(t_fractal *frac);

#endif