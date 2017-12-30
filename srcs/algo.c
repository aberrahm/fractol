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
		x = init_x(point);
		y = init_y(point);
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
                ft_pixel_put(point, point->coord.x, point->coord.y, ROUGEF);
            else
                ft_pixel_put(point, point->coord.x, point->coord.y, (i * FUSHIA) / point->ite);
            point->coord.y++;
        }
        point->coord.x++;
    }
}

void ft_julia(t_all *point)
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
            x = init_x(point);
            y = init_y(point);
            point->nb.c_r = point->mouse_x; 
            point->nb.c_i = point->mouse_y;
            point->nb.z_r = x;
            point->nb.z_i = y;
            i = 0;
            while (point->nb.z_r * point->nb.z_r + point->nb.z_i * point->nb.z_i < 4 && i < point->ite)
            {
                j = point->nb.z_r;
                point->nb.z_r = point->nb.z_r * point->nb.z_r - point->nb.z_i * point->nb.z_i + point->nb.c_r;
                point->nb.z_i = 2.0 * point->nb.z_i * j + point->nb.c_i;
                i++;
            }
            if (i == point->ite)
                ft_pixel_put(point, point->coord.x, point->coord.y, ROUGEF);
            else
                ft_pixel_put(point, point->coord.x, point->coord.y, (i * ROSEC) / point->ite);
            point->coord.y++;
        }
        point->coord.x++;
    }
}