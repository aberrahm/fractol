/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:37:25 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 06:15:06 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	event(t_all img)
{
	mlx_hook(img.win_ptr, 2, 1L << 8, key_hook, &img);
	mlx_hook(img.win_ptr, 6, 1L << 6, mouse_hook_j, (void *)&img);
	mlx_mouse_hook(img.win_ptr, mouse_hook, &img);
}

void	event_m(t_all img)
{
	mlx_hook(img.win_ptr, 2, 1L << 8, key_hook_m, &img);
	mlx_mouse_hook(img.win_ptr, mouse_hook_m, &img);
}

void	event_b(t_all img)
{
	mlx_hook(img.win_ptr, 2, 1L << 8, key_hook_b, &img);
	mlx_mouse_hook(img.win_ptr, mouse_hook_b, &img);
}

int		key_hook(int k, t_all *point)
{
	if (k == K_ESC)
	{
		ft_putstr("fractol closed\n");
		exit(0);
	}
	else if (k == K_LEFT || k == K_RIGHT || k == K_RISE || k == K_DOWN)
	{
		if (k == K_LEFT)
			point->translate.x -= 10;
		else if (k == K_RIGHT)
			point->translate.x += 10;
		else if (k == K_RISE)
			point->translate.y -= 10;
		else if (k == K_DOWN)
			point->translate.y += 10;
		ft_memset((void*)point->data, 0, point->width *
		point->height * sizeof(int));
		ft_julia(point);
		mlx_put_image_to_window(point->mlx_ptr, point->win_ptr,
		point->img_ptr, 0, 0);
	}
	return (0);
}

int		ft_key_exit(int keycode, t_all *point)
{
	exit(keycode);
	return ((int)point);
}
