# include "../includes/fractol.h"

void     event(t_all img)
{
    mlx_hook(img.win_ptr, 4, 1L << 8, mouse_hook_julia, (void*)&img);
   // mlx_mouse_hook(img.win_ptr, mouse_hook, &img);
}
