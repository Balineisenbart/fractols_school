/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoiber <astoiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:08:34 by astoiber          #+#    #+#             */
/*   Updated: 2025/04/22 12:11:44 by astoiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_H
# define CONFIGURATION_H

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	reset_configuration(t_config *config, char *fractal_type);
void	set_fractal_type(t_config *config, char *fractal_type);
void	init_configuration(t_config *config, char *arg);

#endif