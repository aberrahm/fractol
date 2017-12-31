/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:37:00 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/31 22:05:46 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_bship(t_all *point)
{
	int i;
	float zr2;
	float zi2;

	ft_resize(point);
	point->coord.x = 0;
	while (point->coord.x < point->width)
	{
		point->coord.y = 0;
		while (point->coord.y < point->height)
		{
			ft_bship_init(point);
			zr2 = point->nb.z_r * point->nb.z_i;
			zi2 = point->nb.z_i * point->nb.z_i;
			i = 0;
			while (zr2 + zi2 < 4 && i < point->ite)
			{
				point->nb.z_i = fabs(2.0 * point->nb.z_i * point->nb.z_r
						+ point->nb.c_i);
				point->nb.z_r = fabs(zr2 - zi2 + point->nb.c_r);
				zr2 = point->nb.z_r * point->nb.z_r;
				zi2 = point->nb.z_i * point->nb.z_i;
				i++;
			}
			ft_bship_n(point, i);
			point->coord.y++;
		}
		point->coord.x++;
	}
}

void	ft_bship_init(t_all *point)
{
	point->nb.c_r = init_x(point);
	point->nb.c_i = init_y(point);
	point->nb.z_r = 0.0;
	point->nb.z_i = 0.0;
}

void	ft_bship_n(t_all *point, int i)
{
	if (i == point->ite)
		ft_pixel_put(point, point->coord.x, point->coord.y, ROUGEF);
	else
		ft_pixel_put(point, point->coord.x, point->coord.y,
				(i * VERT) / point->ite);
}