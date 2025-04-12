


#include "fractols.h"

int calc_julia(t_fractal *fract, t_complx *c, int x, int y)
{
    
    //zn + 1 = z*2/n + c,z0 = c: c==mouse sets starting position
    double      re_temp;
    t_complex   z;
    int         i;

    i = -1;
    z.re = (x / fract->zoom) + fract->offset_x;
    z.im = (x / fract->zoom) + fract->offset_y;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re + z.im * z.im + c->re;
        z.im = 2 * z.re * z.im + c->im;
        z.re = re_temp;
    }
    return (i);
}

int calc_mandelbrot(t_fractal *fract, t_complex *c)
{

    //zn + 1 = z*2/n + c,z0 = 0 : starting position = c alwas same(0)

    double      re_temp;
    t_complex   z;
    int         i;

    i = -1;
    z.re = 0;
    z.im = 0;

    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c->re;
        z.im = 2 * z.re * z.im + c->im;
        z.re = re_temp;
    }
    return (i);
}