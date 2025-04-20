


#include "fractols.h"
#include "events.h"
#include "configuration.h"
#include "keys.h"
#include "utils.h"

int main(int argc, char **argv)
{
  t_config  config;

  check_input(&config, argc, argv);
  init_configuration(&config, argv[1]);
  draw_fractal(&config);
  mlx_key_hook(config.window, on_key_hook_event, &config);
  mlx_mouse_hook(config.window, on_mouse_hook_event, &config);
  mlx_hook(config.window, 6, 1L << 6, on_mouse_move_event, &config);
  mlx_hook(config.window, 17, 0, on_destroy_event, &config);

  mlx_loop(config.mlx);
  
  return (0);
}
