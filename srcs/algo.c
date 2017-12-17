#include "../includes/fractol.h"
#include <stdio.h>

void ft_mandelbrot(t_all *point)
{
    int i;
    float j;
    float x;
    float y;

    ft_resize(point);
    point->coord.x = 0;
    while (point->coord.x < point->width)
    {
        point->coord.y = 0;
        while (point->coord.y < point->height)
        {
            x = (((float)point->coord.x / (float)point->width) * point->ortho.width) + point->ortho.x1;
            y = ((((float)point->height - (float)point->coord.y) / (float)point->height) * point->ortho.height) + point->ortho.y1;
            point->nb.c_r = x;
            point->nb.c_i = y;
            point->nb.z_r = 0.0;
            point->nb.z_i = 0.0;
            i = 0;
            while (point->nb.z_r * point->nb.z_r + point->nb.z_i * point->nb.z_i < 4 && i < point->ite)
            {
                j = point->nb.z_r;
                point->nb.z_r = point->nb.z_r * point->nb.z_r - point->nb.z_i * point->nb.z_i + point->nb.c_r;
                point->nb.z_i = 2.0 * point->nb.z_i * j + point->nb.c_i;
                i++;
            }
            if (i == point->ite)
                mlx_pixel_put(point->mlx_ptr, point->win_ptr, point->coord.x, point->coord.y, BLANCCA);
            point->coord.y++;
        }
        point->coord.x++;
    }
}

/*int     ft_julia(t_all *point)
{
    int     z;
    int     c;


    z = z * z + c;
    while (z < 4)
    {

        point->ite++;
    }
    return (point->ite);
}*/