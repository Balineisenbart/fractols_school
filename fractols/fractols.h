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


# define WINDOW_SIZE_W 1920
# define WINDOW_SIZE_H 1080
# define WINDOW_STATEMENT "fract'ols"
# define MIN_ITERATIONS 255 //How detailed will my fractal be? = number of possible colors
# define MAX_ITERATIONS 255

/*
needed structs

.s_pixel -> for x/y coordinates
.s_complex -> one struct containing real & complex part
.s_image -> store info needed to print the desired image (img ptr, addr ptr, line length, pixel bits, endian)
.s_config -> stoer all tools to print fractal (mlx ptr, window ptr, image, fractal set, )
s_interact -> interact with the fractal ... like mouse control, zoom, nbr of iterations, color, set type, 
*/

typedef struct s_pixel{
    int x;
    int y;
}   t_pixel;


typedef s_complex{
    double real;
    double imaginary;
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
    ??? color;
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

