/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 04:15:08 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 06:05:18 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_img(t_all *img, char *str)
{
	img->size_win_x = 600;
	img->size_win_y = 360;
	img->width = 600;
	img->height = 360;
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->size_win_x,
			img->size_win_y, str);
	img->img_ptr = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
}

void	ft_resize(t_all *img)
{
	img->ortho.x1 = -2.5;
	img->ortho.x2 = 1.0;
	img->ortho.y1 = 1.0;
	img->ortho.y2 = -1.0;
	img->ite = 110;
	img->ortho.width = (img->ortho.x2 - img->ortho.x1);
	img->ortho.height = (img->ortho.y2 - img->ortho.y1);
}

void	ft_pixel_put(t_all *point, int x, int y, uint32_t color)
{
	uint32_t *pixel;

	if (x < 0 || x >= point->size_win_x || y < 0 || y >= point->size_win_y)
		return ;
	pixel = (uint32_t *)(point->data + x * point->bpp /
			8 + y * point->sizeline);
	*pixel = color;
}
