/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 21:38:29 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 05:59:56 by aberrahm         ###   ########.fr       */
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
		ft_cmp(av[1], point);
		return (EXIT_SUCCESS);
	}
	ft_putendl("Usage : ./fractol [mandelbrot , julia , burningship]");
	return (EXIT_FAILURE);
}

void	ft_cmp(char *str, t_all point)
{
	if (!ft_strcmp(str, "julia"))
	{
		create_img(&point, str);
		event(point);
	}
	else if (!ft_strcmp(str, "mandelbrot"))
	{
		create_img(&point, str);
		event_m(point);
	}
	else if (!ft_strcmp(str, "burningship"))
	{
		create_img(&point, str);
		event_b(point);
	}
	else
	{
		ft_putendl("Usage : ./fractol [mandelbrot , julia , burningship]");
		exit(EXIT_FAILURE);
	}
	ft_norm(point);
}

void	ft_norm(t_all point)
{
	mlx_put_image_to_window(point.mlx_ptr, point.win_ptr, point.img_ptr, 0,0);
	mlx_hook(point.win_ptr, 17, 1L << 17, ft_key_exit, (void *)&point);
	mlx_loop_hook(point.mlx_ptr, refresh, &point);
	mlx_loop(point.mlx_ptr);
}
