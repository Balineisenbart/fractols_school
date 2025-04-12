

# include "fractols.h"

void change_view(int key, t_config *config)
{
    t_config *fr;

    fr = &config->fractal;
    if (key == KEY_W)
        fr->offset_y += VIEW_CHANGE_SIZE / fractal->zoom;
    else if (key == KEY_S)
        fr->offset_y -= VIEW_CHANGE_SIZE / fractal->zoom;
    else if (key == KEY_D)
        fr->offset_x += VIEW_CHANGE_SIZE / fractal->zoom;
    else if (key == KEY_A)
        fr->offset_x -= VIEW_CHANGE_SIZE / fractal->zoom;
}

int clac_fractal(t_fract *fract, t_complex *c, int x, int y)
{
    int iter;

    iter = 0;
    if (fractal.type == MANDELBROT)
        iter = calc_mandelbrot(fract, c);
    else if (fractal.type == JULIA)
        iter = calc_julia(fract, c, x, y);

    return (iter);
}

void set_pixel_color(t_config *config, int x, int y, int color)
{
    int line_len;
    int bits_per_pixel;
    int offest;

    if (x < 0 || y >= WINDOW_SIZE || y < 0 || y >= WINDOW_SIZE)
        return;
    line_len = config->image.line_len;
    bits_per_pixel = config->image.pixel_bits;
    offset = (y * line_length) + (x * (bits_per_pixel / 8))
    *(unsigned int *)(Config->img.addr_ptr + offset) = color;
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

    while (++x < WINDOW_SIZE)
    {
        y = -1;
        if (fract.type != JULIA)
            c.real = (x / fract->zoom)  fract->x_offset;
        while (y < WINDOW_SIZE)
        {
            iter = calc_fractal(fract, &c, x, y);
            set_pixel_color(config, x, y, (iter * config->fractal.color));
        }
    }
    mlx_put_image_to_window(config->mlx, config->window, config.img.img_ptr, 0, 0);
}