#include "../includes/fractol.h"
#include <stdio.h>

/*int mouse_hook(int button, t_all *img)
{
        if (button == 1)
        {
            img->zoom = 0.2;
            img->nb.z_r = init_x(img) * img->zoom;
            img->nb.z_i = init_y(img) * img->zoom;
        }
    return (0);
}*/ //A REVOIRRRR CA PLANTE ICIIII

float     init_x(t_all *point)
{
    float   x;

  x = (((float)point->coord.x / (float)point->width) * point->ortho.width) + point->ortho.x1;
  return (x);
}

float     init_y(t_all *point)
{
    float   y;

    y = ((((float)point->height - (float)point->coord.y) / (float)point->height) * point->ortho.height) + point->ortho.y1;
    return (y);
}