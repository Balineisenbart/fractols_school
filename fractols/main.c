


#include "fractols.h"


int main(int argc, char **argv)
{

  if (!argv == 2)
  {
    return (help_input())
  }

  init_configuration(); //init and open window
  draw_fractal(); //draw in buffer and put
  mlx_mouse_hook(); //create interactable
  mlx_key_hook(); //create interactable

  mlx_loop(mlx);
  
  return (0);
}