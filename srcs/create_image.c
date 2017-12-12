/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 04:15:08 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/09 04:15:11 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void create_img(t_all *img)
{
	img->size_win_x = 1800;
	img->size_win_y = 1200;
	img->width = 1800;
	img->height = 1200;
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->size_win_x,
								  img->size_win_y, "fractol");
	img->img_ptr = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
								  &img->sizeline, &img->endian);
	img->img_win = mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
										   img->img_ptr, 0, 0);
}

void ft_pixel_put(t_all *point, int x, int y, uint32_t color)
{
	uint32_t *pixel;

	if (x < 0 || x >= point->size_win_x || y < 0 || y >= point->size_win_y)
		return;
	pixel = (uint32_t *)(point->data + x * point->bpp / 8 + y * point->sizeline);
	*pixel = color;
}