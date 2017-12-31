/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:37:25 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/31 22:23:17 by aberrahm         ###   ########.fr       */
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
	mlx_hook(img.win_ptr, 2, 1L << 8, key_hook, &img);
	mlx_mouse_hook(img.win_ptr, mouse_hook_m, &img);
}

void	event_b(t_all img)
{
	mlx_hook(img.win_ptr, 2, 1L << 8, key_hook, &img);
	mlx_mouse_hook(img.win_ptr, mouse_hook_b, &img);
}

int		key_hook(int keycode, t_all *point)
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
	}
	return (0);
}

int		ft_key_exit(int keycode, t_all *point)
{
	exit(keycode);
	return ((int)point);
}
