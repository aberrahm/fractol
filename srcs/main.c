/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:38:29 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/31 22:30:01 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		refresh(t_all *point)
{
	mlx_put_image_to_window(point->mlx_ptr,
			point->win_ptr, point->img_ptr, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_all	point;
	int		i;

	point.zoom = 1;
	i = 0;
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "julia"))
		{
			create_img(&point, av[1]);
			event(point);
		}
		if (!ft_strcmp(av[1], "mandelbrot"))
		{
			create_img(&point, av[1]);
			event_m(point);
		}
		if (!ft_strcmp(av[1], "burningship"))
		{
			create_img(&point, av[1]);
			event_b(point);
		}
		ft_norm(point);
	}
	return (0);
}

void	ft_norm(t_all point)
{
	mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0, 0);
	mlx_loop_hook(point.mlx_ptr, refresh, &point);
	mlx_hook(point.win_ptr, 17, 1L << 17, ft_key_exit, (void *)&point);
	mlx_loop(point.mlx_ptr);
}
