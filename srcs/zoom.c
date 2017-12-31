#include "../includes/fractol.h"

int mouse_hook(int button, int x, int y, t_all *img)
{
    if (button == M_LEFT || button == M_MOLUP)
    {
        img->zoom *= 0.8;
        ft_julia(img);
    }
    if (button == M_RIGHT || button == M_MOLDOWN)
    {
        img->zoom *= 1.2;
        ft_julia(img);
    }
    return (x + y);
}

int mouse_hook_m(int button, int x, int y, t_all *img)
{
    if (button == M_LEFT || button == M_MOLUP)
    {
        img->zoom *= 0.8;
        ft_mandelbrot(img);
    }
    if (button == M_RIGHT || button == M_MOLDOWN)
    {
        img->zoom *= 1.2;
        ft_mandelbrot(img);
    }
    return (x + y);
}

int mouse_hook_b(int button, int x, int y, t_all *img)
{
    if (button == M_LEFT || button == M_MOLUP)
    {
        img->zoom *= 0.8;
        ft_bship(img);
    }
    if (button == M_RIGHT || button == M_MOLDOWN)
    {
        img->zoom *= 1.2;
        ft_bship(img);
    }
    return (x + y);
}

int mouse_hook_j(int x, int y, t_all *img)
{
    img->mouse_x = (x - img->size_win_x / 2.0) / img->size_win_x * 2.0;
    img->mouse_y = (y - img->size_win_y / 2.0) / img->size_win_y * 2.0;
    ft_julia(img);
    return (0);
}

float init_x(t_all *point)
{
    float x;

    x = ((((float)point->coord.x + point->translate.x) / (float)point->width) * point->ortho.width) + point->ortho.x1;
    return (x * point->zoom);
}

float init_y(t_all *point)
{
    float y;

    y = ((((float)point->height - (float)point->coord.y) / (float)point->height) * point->ortho.height) + point->ortho.y1;
    return (y * point->zoom);
}