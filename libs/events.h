/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoiber <astoiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:08:38 by astoiber          #+#    #+#             */
/*   Updated: 2025/04/25 14:26:46 by astoiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractol.h"

int	on_destroy_event(t_config *config);
int	on_mouse_hook_event(int key, int x, int y, t_config *config);
int	on_mouse_move_event(int x, int y, t_config *config);
int	on_key_hook_event(int key, t_config *config);

#endif
