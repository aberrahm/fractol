#include "../includes/fractol.h"

void ft_mandelbrot(t_all *point)
{
    int i;
    int j;

    ft_resize(point);
    point->coord.x = 0;
    while (point->coord.x < point->width)
    {
        point->coord.y = 0;
        while (point->coord.y < point->height)
        {
            point->nb.c_r = point->coord.x / point->zoom + point->ortho.x1;
            point->nb.c_i = point->coord.y / point->zoom + point->ortho.y1;
            point->nb.z_r = 0;
            point->nb.z_i = 0;
            i = 0;
            j = point->nb.z_r;
            point->nb.z_r = point->nb.z_r * point->nb.z_r - point->nb.z_i * point->nb.z_i + point->nb.c_r;
            point->nb.z_i = 2 * point->nb.z_i * j + point->nb.c_i;
            i = i + 1;
            while (point->nb.z_r * point->nb.z_r + point->nb.z_i * point->nb.z_i < 4 && i < point->ite)
            {
                if (i == point->ite)
                    ft_pixel_put(point, point->coord.x, point->coord.y, ROSEC);
                else
                    ft_pixel_put(point, point->coord.x, point->coord.y, BLANCCA);
                i++;
            }
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