#include "../includes/fractol.h"

int main(int ac, char **av)
{
    t_all point;
    int i;

    i = 0;
    if (ac && av)
    {
            create_img(&point);
            ft_mandelbrot(&point);
            //ft_pixel_put(&point, 1, 498, ROSEC);
            //ft_pixel_put(&point, 1, 497, ROSEC);
            //ft_pixel_put(&point, 1, 496, ROSEC);
            mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, point.coord.x, point.coord.y);
    }
    mlx_loop(point.mlx_ptr);
    return (0);
}