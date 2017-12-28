#include "../includes/fractol.h"
#include <stdio.h>

/*int mouse_hook(int button, int x, int y, t_all *img)
{
    x = (int)init_mouse_x(img);
    y = (int)init_mouse_y(img);

    if (button == M_LEFT || button == M_MOLUP)
    {
        img->zoom *= 0.8;
        ft_julia(img);
        //ft_lapin(img);
    }
    if (button == M_RIGHT || button == M_MOLDOWN)
    {
        img->zoom *= 1.2;
        ft_julia(img);
        //ft_lapin(img);
    }
    if (x && y)
        ft_julia(img);
    mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
    return (0);
}*/

int mouse_hook_m(int x, int y, t_all *img)
{
    img->mouse_x = (x - img->size_win_x / 2.0) / img->size_win_x * 2.0;
    img->mouse_y = (y - img->size_win_y / 2.0) / img->size_win_y * 2.0;
    ft_julia(img);
    return (0);
}

/*int mouse_hook_julia(int x, int y, t_all *img)
{
        if (x < img->size_win_x && x < img->size_win_y &&
            y < img->size_win_x && y < img->size_win_y)
        {
            img->nb.c_r = (float)x;
            img->nb.c_i = (float)y;
        }
        mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
    return (0);
}*/

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
