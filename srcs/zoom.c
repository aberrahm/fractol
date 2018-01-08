/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:40:25 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 05:55:38 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "stdio.h"

int		mouse_hook(int button, int x, int y, t_all *img)
{
	if (button == M_LEFT || button == M_MOLUP)
	{
		img->zoom *= 0.8;
		ft_julia(img);
	}
	if (button == M_RIGHT || button == M_MOLDOWN)
	{
		img->zoom *= 1.2;
		ft_julia(img);
	}
	return (x + y);
}

int		mouse_hook_m(int button, int x, int y, t_all *img)
{
	float fx;
	float fy;

	fx = (float)(x - img->width / 2.0) / img->width * img->ortho.width;
	fy = (float)(y - img->height / 2.0) / img->height * img->ortho.height;
	if (button == M_LEFT || button == M_MOLUP)
	{
		img->zoom *= 0.8;
	//	img->ortho.x1 -= 0.5;
		//img->ortho.y1 -= 0.5;
	printf("orthox1 : %f\n", img->ortho.x1);
	printf("orthoy1 : %f\n", img->ortho.y1);
	printf("orthox : %f\n", img->ortho.width);
	printf("orthoy : %f\n", img->ortho.height);
	printf("x: %f\n", fx);
	printf("y: %f\n\n", fy);

		ft_mandelbrot(img);
	}
	if (button == M_RIGHT || button == M_MOLDOWN)
	{
		img->zoom *= 1.2;
		ft_mandelbrot(img);
	}
	return (x + y);
}

int		mouse_hook_b(int button, int x, int y, t_all *img)
{
	if (button == M_LEFT || button == M_MOLUP)
	{
		img->zoom *= 0.8;
		ft_bship(img);
	}
	if (button == M_RIGHT || button == M_MOLDOWN)
	{
		img->zoom *= 1.2;
		ft_bship(img);
	}
	return (x + y);
}

int		mouse_hook_j(int x, int y, t_all *img)
{
	img->mouse_x = (x - img->size_win_x / 2.0) / img->size_win_x * 2.0;
	img->mouse_y = (y - img->size_win_y / 2.0) / img->size_win_y * 2.0;
	ft_julia(img);
	return (0);
}
