/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoiber <astoiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:09:17 by astoiber          #+#    #+#             */
/*   Updated: 2025/04/25 14:48:06 by astoiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <ctype.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

double	ft_atof(const char *s, int i)
{
	double	res;
	double	sign;
	double	frac;

	res = 0.0;
	sign = 1.0;
	frac = 0.1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1.0;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			res += (s[i++] - '0') * frac;
			frac *= 0.1;
		}
	}
	return (res * sign);
}

int	is_valid_number(const char *s)
{
	int	i;
	int	has_digit;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	has_digit = 0;
	while (s[i])
	{
		if (isdigit(s[i]) || s[i] == '.')
		{
			if (isdigit(s[i]))
				has_digit = 1;
			i++;
		}
		else
			return (0);
	}
	return (has_digit);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	check_input(t_config *config, int argc, char **argv)
{
	int	i;

	i = 0;
	if (!(argc == 2 || argc == 4))
		help_input();
	if (!(ft_strcmp(argv[1], MANDELBROT) == 0 || ft_strcmp(argv[1],
				JULIA) == 0))
		help_input();
	if ((ft_strcmp(argv[1], MANDELBROT) == 0) && argc > 2)
		help_input();
	if (ft_strcmp(argv[1], JULIA) == 0)
	{
		if (argc == 4)
		{
			if (!(is_valid_number(argv[2]) && is_valid_number(argv[3])))
				help_input();
			else
			{
				config->arg2 = ft_atof(argv[2], i);
				config->arg3 = ft_atof(argv[3], i);
				config->complex_param_lock_flag = 1;
			}
		}
	}
}
