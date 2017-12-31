/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:40:04 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/31 22:47:59 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot(t_all *point)
{
	int		i;
	float	j;

	ft_resize(point);
	point->coord.x = 0;
	while (point->coord.x < point->width)
	{
		point->coord.y = 0;
		while (point->coord.y < point->height)
		{
			ft_mandel_init(point);
			i = 0;
			ft_mandel_n2(point, j, i);
			ft_mandel_n(point, i);
			point->coord.y++;
		}
		point->coord.x++;
	}
}

void	ft_mandel_init(t_all *point)
{
	float	x;
	float	y;

	x = init_x(point);
	y = init_y(point);
	point->nb.c_r = x;
	point->nb.c_i = y;
	point->nb.z_r = 0.0;
	point->nb.z_i = 0.0;	
}

void	ft_mandel_n(t_all *point, int i)
{
	if (i == point->ite)
		ft_pixel_put(point, point->coord.x, point->coord.y, ROUGEF);
	else
		ft_pixel_put(point, point->coord.x, point->coord.y, (i * FUSHIA) / point->ite);
}

void	ft_mandel_n2(t_all *point, float j, int i)
{
	while (point->nb.z_r * point->nb.z_r + point->nb.z_i *
			point->nb.z_i < 4 && i < point->ite)
	{
		j = point->nb.z_r;
		point->nb.z_r = point->nb.z_r * point->nb.z_r - point->nb.z_i *
			point->nb.z_i + point->nb.c_r;
		point->nb.z_i = 2.0 * point->nb.z_i * j + point->nb.c_i;
		i++;
	}
}
