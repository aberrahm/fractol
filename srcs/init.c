/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 22:31:16 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 05:59:48 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	init_x(t_all *point)
{
	float	x;

	x = ((((float)point->coord.x + point->translate.x) /
				(float)point->width) * point->ortho.width) + point->ortho.x1;
	return (x * point->zoom);
}

float	init_y(t_all *point)
{
	float	y;

	y = ((((float)point->coord.y - (float)point->translate.y) /
				(float)point->height) * point->ortho.height) + point->ortho.y1;
	return (y * point->zoom);
}
