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
	if (button == M_LEFT || button == M_MOLUP)
	{
		img->zoom *= 0.8;
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
