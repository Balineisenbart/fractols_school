/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoiber <astoiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:09:12 by astoiber          #+#    #+#             */
/*   Updated: 2025/04/22 12:58:48 by astoiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "events.h"
#include "fractols.h"
#include "keys.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_config	config;

	check_input(&config, argc, argv);
	init_configuration(&config, argv[1]);
	draw_fractal(&config);
	mlx_key_hook(config.window, on_key_hook_event, &config);
	mlx_mouse_hook(config.window, on_mouse_hook_event, &config);
	mlx_hook(config.window, 6, 1L << 6, on_mouse_move_event, &config);
	mlx_hook(config.window, 17, 0, on_destroy_event, &config);
	mlx_loop(config.mlx);
	return (0);
}

void	help_input(void)
{
	write(1, "Programm calls as follows:\n", 27);
	write(1,
		"./<Binar> <fractal set> <real number> <imaginary number>\n", 54);
	write(1, "fractal set must be written in small letters\n", 45);
	write(1, "Programm offers two sets: mandelbrot or julia\n", 46);
	write(1, "mandelbrot needs no extra input\n", 32);
	write(1, "julia handels complex number\n", 29);
	exit(EXIT_SUCCESS);
}
