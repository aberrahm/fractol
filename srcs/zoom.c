#include "../includes/fractol.h"
#include <stdio.h>

int mouse_hook(int button, int x, int y, t_all *img)
{
    x = img->coord.x;
    y = img->coord.y;

    if (button == M_LEFT || button == M_MOLUP)
    {
        img->zoom *= 0.8;
        //ft_mandelbrot(img);
        // ft_julia(img);
        //ft_lapin(img);
    }
    if (button == M_RIGHT || button == M_MOLDOWN)
    {
        img->zoom *= 1.2;
        //ft_mandelbrot(img);
        //ft_julia(img);
        //ft_lapin(img);
    }
    mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
    return (0);
}

int mouse_hook_julia(int button, int x, int y, t_all *img)
{
    x = img->coord.x;
    y = img->coord.y;

        if (button == M_LEFT && img->coord.x < img->size_win_x && img->coord.x < img->size_win_y &&
            img->coord.y < img->size_win_x && img->coord.y < img->size_win_y)
        {
            img->nb.c_r += 1.0;
            img->nb.c_i += 1.0;
        }
        mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
    return (0);
}

float   init_c_r(t_all *point)
{
    point->nb.c_r = 0.285;
    return (point->nb.c_r);
}

float   init_c_i(t_all *point)
{
    point->nb.c_i = 0.01;
    return (point->nb.c_i);
}

float init_x(t_all *point)
{
    float x;

    x = (((float)point->coord.x / (float)point->width) * point->ortho.width) + point->ortho.x1;
    return (x * point->zoom);
}

float init_y(t_all *point)
{
    float y;

    y = ((((float)point->height - (float)point->coord.y) / (float)point->height) * point->ortho.height) + point->ortho.y1;
    return (y * point->zoom);
}
