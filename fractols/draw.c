

# include "fractols.h"
# include "keys.h"

void change_view(int key, t_config *config)
{
    t_fractal *fr;

    fr = &config->fractal;
    if (key == KEY_W)
        fr->offset_y += VIEW_CHANGE_SIZE / fr->zoom;
    else if (key == KEY_S)
        fr->offset_y -= VIEW_CHANGE_SIZE / fr->zoom;
    else if (key == KEY_D)
        fr->offset_x += VIEW_CHANGE_SIZE / fr->zoom;
    else if (key == KEY_A)
        fr->offset_x -= VIEW_CHANGE_SIZE / fr->zoom;
}

int calc_fractal(t_fractal *fract, t_complex *c, int x, int y)
{
    int iter;

    iter = 0;
    if (!(ft_strcmp(fract->type, MANDELBROT)))
    {
        printf("cheking for mandelbrot\n");
        iter = calc_mandelbrot(fract, c);
        printf("iter: %d\n", iter);
    }
    else if (!(ft_strcmp(fract->type, JULIA)))
    {
        printf("cheking for julia\n");
        iter = calc_julia(fract, c, x, y);
        printf("iter: %d\n", iter);
    }

    return (iter);
}

void set_pixel_color(t_config *config, int x, int y, int color)
{
    int line_len;
    int bits_per_pixel;
    int offset;

    if (x < 0 || y >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
        return;
    line_len = config->image.line_length;
    bits_per_pixel = config->image.pixel_bits;
    offset = (y * line_len) + (x * (bits_per_pixel / 8));
    *(unsigned int *)(config->image.addr_ptr + offset) = color;
}

void draw_fractal(t_config *config)
{
    static t_complex    c;
    t_fractal           *fract;
    int                 iter;
    int                 x;
    int                 y;

    fract = &config->fractal;
    x = -1;
    mlx_clear_window(config->mlx, config->window);

    while (++x < WIN_SIZE)
    {
        printf("entered fractal loop\n");

        y = -1;
        if (!(ft_strcmp(fract->type, JULIA)))
            c.re = (x / fract->zoom) + fract->offset_x;

        while (y < WIN_SIZE)
        {
            iter = calc_fractal(fract, &c, x, y);
            printf("%i\n", iter);
            set_pixel_color(config, x, y, (iter * config->fractal.color));
        }
    }
    mlx_put_image_to_window(config->mlx, config->window, config->image.img_ptr, 0, 0);
}