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

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIN_SIZE 800
# define WINDOW_STATEMENT "fract'ols"
# define MIN_ITERATIONS 255
# define MAX_ITERATIONS 255
# define DEFAULT_COLOR 0x000A0F
# define VIEW_CHANGE_SIZE 60

# define SCALE 2
# define FIXED_RADIUS 1
# define MIN_RADIUS 0.5

# define JULIA "julia"
# define MANDELBROT "mandelbrot"


typedef struct s_complex{
    double re;
    double im;
}   t_complex;

typedef struct s_image{
    void    *img_ptr;
    char    *addr_ptr;
    int     line_length;
    int     pixel_bits;
    int     endian;
}   t_image;

typedef struct s_fractal{
    char *type;
    double zoom;
    double mouse_x;
    double mouse_y;
    int color;
    int iterations;
    double offset_x;
    double offset_y;
}   t_fractal;


typedef struct s_config{
    void        *mlx;
    void        *window;
    int         complex_param_lock_flag;
    double         arg2;
    double         arg3;
    t_image     image;
    t_fractal   fractal;
}   t_config;


void change_view(int key, t_config *config);
int calc_fractal(t_fractal *fract, t_complex *c, int x, int y);
void set_pixel_color(t_config *config, int x, int y, int color);
void draw_fractal(t_config *config);
int calc_julia(t_fractal *fract, t_complex *c, int x, int y);
int calc_mandelbrot(t_fractal *fract, t_complex *c);
int	ft_strcmp(const char *s1, const char *s2);
void check_input(t_config *config, int argc, char **argv);
int ft_is_valid_number(const char *s);
double	ft_atof(const char *s);
int	ft_isdigit(int c);
void help_input(void);

#endif

