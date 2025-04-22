

#include "fractols.h"
#include "events.h"
#include "keys.h"
#include "mlx.h"

int on_destroy_event(t_config *config)
{
    mlx_destroy_image(config->mlx, config->image.img_ptr);
    mlx_destroy_window(config->mlx, config->window);
    exit(EXIT_SUCCESS);
    return (0);
}

int on_mouse_hook_event(int key, int x, int y, t_config *config)
{
    t_fractal *fr;

    fr = &config->fractal;
    if (key == MOUSE_SCRL_DOWN)
    {
        fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
        fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
        fr->zoom *= 1.3;

        if (fr->iterations < MAX_ITERATIONS)
            fr->iterations++;
    }
    if (key == MOUSE_SCRL_UP)
    {
        fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
        fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
        fr->zoom /= 1.3;

        if (fr->iterations < MAX_ITERATIONS)
            fr->iterations++;
    }
    draw_fractal(config);
    return (0);
}

int on_mouse_move_event(int x, int y, t_config *config)
{
    if(ft_strcmp(config->fractal.type, JULIA))
        return (0);
    config->fractal.mouse_x = x;
    config->fractal.mouse_y = y;
    draw_fractal(config);
    return (0);
}

int on_key_hook_event(int key, t_config *config)
{
    if (key == KEY_ESC)
    {
        on_destroy_event(config);
        return (0);
    }
    else if (key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A)
        change_view(key, config);
    draw_fractal(config);
    return (0);
}