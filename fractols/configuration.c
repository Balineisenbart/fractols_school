

#include "fractols.h"
#include "configuration.h"

void my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
    char    *dst;

    dst = image->addr_ptr + (y * image->line_length + x * (image->pixel_bits / 8));
    *(unsigned int*)dst = color;
}

void reset_configuration(t_config *config, char *fractal_type)
{
    config->fractal.type = fractal_type;
    config->fractal.zoom = WIN_SIZE / 4;
    config->fractal.mouse_x = 0;
    config->fractal.mouse_y = 0;
    config->fractal.color = DEFAULT_COLOR;
    config->fractal.iterations = MIN_ITERATIONS;
    config->fractal.offset_x = -2;
    config->fractal.offset_y = -2;
}

void set_fractal_type(t_config *config, char *fractal_type)
{
    config->fractal.type = fractal_type;
}

void init_configuration(t_config *config, char *arg)
{
    int line_length;
    int pixel_bits;
    int endian;

    reset_configuration(config, arg);
    set_fractal_type(config, arg);

    config->mlx = mlx_init();
    config->window = mlx_new_window(config->mlx, WIN_SIZE, WIN_SIZE, WINDOW_STATEMENT);

    config->image.img_ptr = mlx_new_image(config->mlx, WIN_SIZE, WIN_SIZE);
    config->image.addr_ptr = mlx_get_data_addr(config->image.img_ptr, &pixel_bits, &endian, &line_length);

    //config->image = my_mlx_pixel_put(config->image, config->fractal.offset_x, config->fractal.offset_y, config->fractal.color);
    //mlx_put_image_to_window(config->mlx, config->mlx_window, config->image, config->fractal.offset_x, config->fractal.offset_y);

    config->image.pixel_bits = pixel_bits;
    config->image.line_length = line_length;
    config->image.endian = endian;
}