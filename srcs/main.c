#include "../includes/fractol.h"

int main(int ac, char **av)
{
    t_all point;
    int i;

    i = 0;
    if (ac && av)
    {
            create_img(&point);
            ft_pixel_put(&point, 1000, 600, BLANCCA);
            ft_pixel_put(&point, 1001, 600, BLANCCA);
            ft_pixel_put(&point, 1002, 600, BLANCCA);
            ft_pixel_put(&point, 1003, 600, BLANCCA);
            ft_pixel_put(&point, 1004, 600, BLANCCA);
           // mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0, 0);
            create_img_top(&point);
    }
    mlx_loop(point.mlx_ptr);
    return (0);
}