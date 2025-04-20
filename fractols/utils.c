
#include "fractols.h"
#include "configuration.h"
#include "events.h"
#include "keys.h"
#include "mlx.h"
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

double	ft_atof(const char *s)
{
	double	res = 0.0;
	double	sign = 1.0;
	double	frac = 0.1;
	int		i = 0;

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

int is_valid_number(const char *s)
{
    int i = 0;
    if (!s)
        return (0);
    if (s[i] == '-' || s[i] == '+')
        i++;
    int has_digit = 0;
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
    return has_digit;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void check_input(t_config *config, int argc, char **argv)
{
	if (!(argc == 2 || argc == 4))
		help_input();
	if (!(ft_strcmp(argv[1], MANDELBROT) == 0 || ft_strcmp(argv[1], JULIA) == 0))
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
				config->arg2 = ft_atof(argv[2]);
				config->arg3 = ft_atof(argv[3]);
				config->complex_param_lock_flag = 1;
			}
		}
	}
}

void help_input(void)
{
	write(1, "Programm calls as follows:\n", 27);
	write(1, "./<Binar> <fractal set> <possible real number> possible imaginary number>\n", 74);
	write(1, "fractal set must be written in small letters\n", 45);
	write(1, "Programm offers two sets: mandelbrot or julia\n", 46);
	write(1, "mandelbrot needs no extra input\n", 32);
	write(1, "julia runs without extra input, but starting complex number might be provided\n", 78);
	exit(EXIT_SUCCESS);
}