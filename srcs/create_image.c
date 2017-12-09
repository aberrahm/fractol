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

void	create_img(t_all *img)
{
	img->size_win_x = 1000;
	img->size_win_y = 1000;
	img->width = 1000;
	img->height = 1000;
	img->mlx_ptr = mlx_init();
	img->img_ptr = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->size_win_x,
			img->size_win_y, "fractol");
	img->img_win = mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
			img->img_ptr, 0, 0);
}
