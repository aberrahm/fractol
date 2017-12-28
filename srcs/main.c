#include "../includes/fractol.h"
#include <stdio.h>

int refresh(t_all *point)
{
  mlx_put_image_to_window(point->mlx_ptr, point->win_ptr, point->img_ptr, 0, 0);
  return(0);
}

int main(int ac, char **av)
{
  t_all point;
  int i;

  point.zoom = 1;
  i = 0;
  if (ac && av)
  {
    create_img(&point);
    event(point);
    mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0, 0);
  }

  mlx_loop_hook(point.mlx_ptr, refresh, &point);
  mlx_loop(point.mlx_ptr);
  return (0);
}
