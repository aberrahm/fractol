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

void	create_img_top(t_all *imgt)
{
	imgt->width = 1000;
	imgt->height = 1000;

	mlx_new_image(imgt->mlx_ptr, imgt->width, imgt->height);
	ft_pixel_put(imgt, 500, 200, BLANCCA);
	ft_pixel_put(imgt, 501, 200, BLANCCA);
	ft_pixel_put(imgt, 502, 200, BLANCCA);
	ft_pixel_put(imgt, 503, 200, BLANCCA);
	ft_pixel_put(imgt, 504, 200, BLANCCA);
	ft_pixel_put(imgt, 505, 200, BLANCCA);
	ft_pixel_put(imgt, 506, 200, BLANCCA);
	ft_pixel_put(imgt, 507, 200, BLANCCA);
	mlx_put_image_to_window(imgt->mlx_ptr, imgt->win_ptr, imgt->img_ptr, 100, 400);
}

void ft_pixel_put(t_all *point, int x, int y, uint32_t color)
{
	uint32_t *pixel;

	if (x < 0 || x >= point->size_win_x || y < 0 || y >= point->size_win_y)
		return;
	pixel = (uint32_t *)(point->data + x * point->bpp / 8 + y * point->sizeline);
	*pixel = color;
}