#include "../includes/fractol.h"

int main(int ac, char **av)
{
    t_all point;
    int i;

    i = 0;
    if (ac && av)
    {
            create_img(&point);
           // ft_mandelbrot(&point);
            ft_julia(&point);
            //mlx_mouse_hook(point.win_ptr, mouse_hook, &point); CA PLANTE ICI AUSSI
            mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0, 0);
    }
    mlx_loop(point.mlx_ptr);
    return (0);
}