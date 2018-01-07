/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:37:00 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 03:01:35 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_bship(t_all *p)
{
	ft_resize(p);
	p->coord.x = 0;
	while (p->coord.x < p->width)
	{
		p->coord.y = 0;
		while (p->coord.y < p->height)
		{
			ft_bship_init(p);
			ft_bship_b(p);
			p->coord.y++;
		}
		p->coord.x++;
	}
}

void	ft_bship_b(t_all *p)
{
	int		i;
	float	zr;
	float	zi;

	zr = p->nb.z_r * p->nb.z_i;
	zi = p->nb.z_i * p->nb.z_i;
	i = 0;
	while (zr + zi < 4 && i < p->ite)
	{
		p->nb.z_i = fabs(-2.0 * p->nb.z_i * p->nb.z_r
				+ p->nb.c_i);
		p->nb.z_r = fabs(zr - zi + p->nb.c_r);
		zr = p->nb.z_r * p->nb.z_r;
		zi = p->nb.z_i * p->nb.z_i;
		i++;
	}
	ft_bship_n(p, i);
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
