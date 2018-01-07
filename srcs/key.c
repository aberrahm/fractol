/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 00:08:15 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 00:08:31 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook_m(int k, t_all *point)
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
		ft_mandelbrot(point);
		mlx_put_image_to_window(point->mlx_ptr, point->win_ptr,
		point->img_ptr, 0, 0);
	}
	return (0);
}

int		key_hook_b(int k, t_all *point)
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
		ft_bship(point);
		mlx_put_image_to_window(point->mlx_ptr, point->win_ptr,
		point->img_ptr, 0, 0);
	}
	return (0);
}
