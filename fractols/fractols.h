/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoiber <astoiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:40:09 by codespace         #+#    #+#             */
/*   Updated: 2025/03/20 12:03:06 by astoiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#   define FRACTOL_H

//#include "libft/libft.h"
# include <mlx.h>
#include "events.h"


# define WIN_SIZE 800 //height * width
# define WINDOW_STATEMENT "fract'ols"
# define MIN_ITERATIONS 255 //How detailed will my fractal be? = number of possible colors
# define MAX_ITERATIONS 255
# define DEFAULT_COLOR 265
# define VIEW_CHANGE_SIZE 60

# define SCALE 2
# define FIXED_RADIUS 1
# define MIN_RADIUS 0.5

typedef struct s_pixel{
    int x;
    int y;
}   t_pixel;


typedef s_complex{
    double re;
    double im;
}   t_complex;


typedef s_image{
    void    *img_ptr;
    char    *addr_ptr:
    int     line_length; //default by hardware
    int     pixel_bits; //default by hardware
    int     endian; //default by hardware
}   t_image;

typedef s_fractal{
    int type;
    double zoom;
    double mouse_x;
    double mouse_y;
    u_int_32_t color;
    int iterations;
    double offset_x;
    double offset_y;
}   t_fractal


typedef s_config{
    void        *mlx;
    void        *window:
    t_image     image;
    t_image     replace; //not sure if needed, but idea is to avoid screen tearing w/ my_mlx_pixel_put ... buffer
    t_fractal   fractal;
}   t_config;




#endif

