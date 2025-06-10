/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:22:27 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/10 17:49:13 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	fr_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || !n)
		return (0);
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	fr_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static double	parse_fractional_part(const char *str, size_t	*i)
{
	double	digit;
	double	fraction;
	double	divider;

	digit = 0;
	fraction = 0.0;
	divider = 10.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		digit = str[*i] - '0';
		fraction = fraction + (digit / divider);
		divider = divider * 10;
		(*i)++;
	}
	return (fraction);
}

double	fr_atod(const char *str)
{
	size_t	i;
	double	num;
	double	sign;

	i = 0;
	num = 0.0;
	sign = 1.0;
	while (str[i] && is_delim(str[i]))
		i++;
	if (is_sign(str[i]))
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	num += parse_fractional_part(str, &i);
	return (sign * num);
}
