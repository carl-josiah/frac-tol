/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:53:17 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/03 15:32:48 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	has_multiple_dot(char *str)
{
	size_t	i;
	int		has_dot;

	i = 0;
	has_dot = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (1);
			has_dot = 1;
		}
		i++;
	}
	return (0);
}

static int	is_valid_param(char *param)
{
	int		has_digit;
	size_t	i;

	i = 0;
	has_digit = 0;
	while (param[i] && is_delim(param[i]))
		i++;
	if (is_sign(param[i]))
		i++;
	if (has_multiple_dot(&param[i]))
		return (0);
	while (param[i])
	{
		if (param[i] == '.')
			i++;
		if (is_digit(param[i]))
		{
			has_digit = 1;
			i++;
		}
		else
			return (0);
	}
	return (has_digit);
}

static int	is_valid_julia(char *param1, char *param2)
{
	if (is_valid_param(param1) && is_valid_param(param2))
		return (1);
	return (0);
}

int	which_fractal(int ac, char *fractal)
{
	if (ac == DEFAULT_AC && !fr_strncmp(fractal, "mandelbrot", 10))
		return (MANDELBROT);
	else if (ac == DEFAULT_AC && !fr_strncmp(fractal, "julia", 5))
		return (JULIA);
	else if (ac == JULIA_AC && !fr_strncmp(fractal, "julia", 5))
		return (JULIA_WITH_PARAMS);
	else
		return (0);
}

int	has_error(t_fractal *frac, int ac, char **av)
{
	frac->type = which_fractal(ac, av[1]);
	if (frac->type == 0)
		return (1);
	else if (frac->type == MANDELBROT)
		return (0);
	else if (frac->type == JULIA_WITH_PARAMS && ac == JULIA_AC)
	{
		if (is_valid_julia(av[2], av[3]))
			return (0);
		else
			return (1);
	}
	return (0);
}
