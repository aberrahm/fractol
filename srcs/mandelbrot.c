/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:40:04 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 02:00:05 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot(t_all *p)
{
	int		i;

	ft_resize(p);
	p->coord.x = 0;
	while (p->coord.x < p->width)
	{
		p->coord.y = 0;
		while (p->coord.y < p->height)
		{
			ft_mandel_init(p);
			i = 0;
			while (p->nb.z_r * p->nb.z_r + p->nb.z_i *
					p->nb.z_i < 4 && i < p->ite)
			{
				ft_tricks(p);
				i++;
			}
			ft_mandel_n(p, i);
			p->coord.y++;
		}
		p->coord.x++;
	}
}

void	ft_tricks(t_all *p)
{
	float	j;

	j = p->nb.z_r;
	p->nb.z_r = p->nb.z_r * p->nb.z_r - p->nb.z_i * p->nb.z_i + p->nb.c_r;
	p->nb.z_i = 2.0 * p->nb.z_i * j + p->nb.c_i;
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
		ft_pixel_put(point, point->coord.x, point->coord.y,
				(i * FUSHIA) / point->ite);
}
