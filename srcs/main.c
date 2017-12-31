#include "../includes/fractol.h"

int refresh(t_all *point)
{
  mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img_ptr, 0, 0);
  return (0);
}

int main(int ac, char **av)
{
  t_all point;
  int i;

  point.zoom = 1;
  i = 0;
  if (ac == 2)
  {
    if (!ft_strcmp(av[1], "julia"))
    {
      create_img(&point, av[1]);
      event(point);
      mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0, 0);
    }
    if (!ft_strcmp(av[1], "mandelbrot"))
    {
      create_img(&point, av[1]);
      event_m(point);
      mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0, 0);
    }
    if (!ft_strcmp(av[1], "burningship"))
    {
      create_img(&point, av[1]);
      event_b(point);
      mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0, 0);
    }
    mlx_loop_hook(point.mlx_ptr, refresh, &point);
    mlx_hook(point.win_ptr, 17, 1L << 17, ft_key_exit, (void*)&point);
    mlx_loop(point.mlx_ptr);
  }
  return (0);
}
