


#include "fractols.h"
#include "events.h"
#include "configuration.h"
#include "keys.h"

#include <stdio.h>

int main(int argc, char **argv)
{
  t_config config;

  if (!(argc == 2))
  {
    return (0);//help_input()
  }
  init_configuration(&config, argv[1]); //init and open window
  printf("start drawing\n");
  draw_fractal(&config);
  printf("finsih\n");

  mlx_key_hook(config.window, on_key_hook_event, &config);
  mlx_mouse_hook(config.window, on_mouse_hook_event, &config);
  mlx_hook(config.window, 6, 1L << 6, on_mouse_move_event, &config);
  mlx_hook(config.window, 17, 0, on_destroy_event, &config);
  mlx_loop(config.mlx);
  
  return (0);
}