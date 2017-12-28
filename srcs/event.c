# include "../includes/fractol.h"

void     event(t_all img)
{
    mlx_hook(img.win_ptr, 6, 1L << 6, mouse_hook_m, (void*)&img);
   // mlx_mouse_hook(img.win_ptr, mouse_hook, &img);
}
