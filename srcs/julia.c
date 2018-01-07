/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:38:17 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 02:02:43 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_all *point)
{
	int		i;

	ft_resize(point);
	point->coord.x = 0;
	while (point->coord.x < point->width)
	{
		point->coord.y = 0;
		while (point->coord.y < point->height)
		{
			ft_julia_init(point);
			i = 0;
			while (point->nb.z_r * point->nb.z_r + point->nb.z_i *
					point->nb.z_i < 4 && i < point->ite)
			{
				ft_julia_b(point);
				i++;
			}
			ft_julia_n(point, i);
			point->coord.y++;
		}
		point->coord.x++;
	}
}

void	ft_julia_init(t_all *point)
{
	float	x;
	float	y;

	x = init_x(point);
	y = init_y(point);
	point->nb.c_r = point->mouse_x;
	point->nb.c_i = point->mouse_y;
	point->nb.z_r = x;
	point->nb.z_i = y;
}

void	ft_julia_b(t_all *point)
{
	float	j;

	j = point->nb.z_r;
	point->nb.z_r = point->nb.z_r * point->nb.z_r - point->nb.z_i *
		point->nb.z_i + point->nb.c_r;
	point->nb.z_i = 2.0 * point->nb.z_i * j + point->nb.c_i;
}

void	ft_julia_n(t_all *point, int i)
{
	if (i == point->ite)
		ft_pixel_put(point, point->coord.x, point->coord.y, ROUGEF);
	else
		ft_pixel_put(point, point->coord.x, point->coord.y,
				(i * ROSEC) / point->ite);
}
