

#include "fractols.h"

void my_mlx_pixel_put(t_image image, int x, int y, int color)
{
    //be carful to create a second buffer image upon image change - separate struct?
    char    *dst;

    dst = image->addr_ptr + (y * line_length + x * (bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

//default configutation of config.>fractal
void reset_configuration(t_config config*, int fractal_type)
{
    config->fractal.type = fractal_type;
    config->fractal.zoom = ???;
    config->fractal.mouse_x = 0;
    config->fractal. mouse_y = 0;
    config->fractal.color = ???;
    config->fractal.iterations = MIN_ITERATIONS;
    config->fractal. offset_x = -2;
    config->fractal. offset_y = -2;
}

void set_fractal_type(t_config *config, char argv)
{
    config->fractal.type = argv;
}

//set the initial stats for config strcuts. 
void init_configuration(t_config *config, char *argv)
{
    static t_config config;
    t_image         image;

    reset_config();
    set_fractal_type(t_config *config, argv);

    config->mlx = mlx_init();
    config->mlx_window = mlx_new_window(config->mlx, WINDOW_SIZE_W, WINDOW_SIZE_H, WINDOW_STATEMENT);

    image.img_ptr = mlx_new_image(config->mlx, WINDOW_SIZE_W, WINDOW_SIZE_H);
    image.addr_ptr = mlx_get_data_adress(image.img_ptr, &image.pixel_bits, &image.endian, &image.line_length);

    config.image = my_mlx_pixel_put(config->mlx, "t_pixel x". "t_pixel y", "color") //not sure yet how to pass "color" ->iterable?
    mlx_put_image_to_window(config->mlx, config->mlx_window, config.image, "t_pixel x". "t_pixel y");



    config->image.pixel_bits = pixel_bits;
    config->image.line_length = line_length;
    config->image.endian = endian;
}