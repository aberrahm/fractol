#include "../includes/fractol.h"

void event(t_all img)
{
    mlx_hook(img.win_ptr, 2, 1L << 8, key_hook, &img);
    mlx_hook(img.win_ptr, 6, 1L << 6, mouse_hook_m, (void *)&img);
    mlx_mouse_hook(img.win_ptr, mouse_hook, &img);
}

int key_hook(int keycode, t_all *point)
{
    if (keycode == K_ESC)
    {
        ft_putstr("fractol closed\n");
        exit(0);
    }
    else if (keycode == K_LEFT || keycode == K_RIGHT || 
    keycode == K_RISE || keycode == K_DOWN)
    {
        if (keycode == K_LEFT)
            point->translate.x -= 10;
        else if (keycode == K_RIGHT)
            point->translate.x += 10;
        else if (keycode == K_RISE)
            point->translate.y -= 10;
        else if (keycode == K_DOWN)
            point->translate.y += 10;
        else if (keycode == K_ENTER)
            
    }
    return (0);
}