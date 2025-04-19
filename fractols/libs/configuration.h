


#ifndef CONFIGURATION_h
# define    CONFIGURATION_h

void my_mlx_pixel_put(t_image *image, int x, int y, int color);
void reset_configuration(t_config *config, char *fractal_type);
void set_fractal_type(t_config *config, char *fractal_type);
void init_configuration(t_config *config, char *arg);

#endif