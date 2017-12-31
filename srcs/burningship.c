#include "../includes/fractol.h"

void ft_bship(t_all *point)
{
    int i;
    float zr2;
    float zi2;

    ft_resize(point);
    point->coord.x = 0;
    while (point->coord.x < point->width)
    {
        point->coord.y = 0;
        while (point->coord.y < point->height)
        {
            point->nb.c_r = init_x(point);
            point->nb.c_i = init_y(point);
            point->nb.z_r = 0.0;
            point->nb.z_i = 0.0;
            i = 0;
            zr2 = point->nb.z_r * point->nb.z_r;
            zi2 = point->nb.z_i * point->nb.z_i;
            while (zr2 + zi2 < 4 && i < point->ite)
            {
                point->nb.z_i = fabs(2.0 * point->nb.z_i * point->nb.z_r + point->nb.c_i);
                point->nb.z_r = fabs(zr2 - zi2 + point->nb.c_r);
                zr2 = point->nb.z_r * point->nb.z_r;
                zi2 = point->nb.z_i * point->nb.z_i;
                i++;
            }
            if (i == point->ite)
                ft_pixel_put(point, point->coord.x, point->coord.y, ROUGEF);
            else
                ft_pixel_put(point, point->coord.x, point->coord.y, (i * ROUGE) / point->ite);
            point->coord.y++;
        }
        point->coord.x++;
    }
}