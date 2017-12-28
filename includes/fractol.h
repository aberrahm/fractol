/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 03:01:00 by aberrahm          #+#    #+#             */
/*   Updated: 2017/12/09 03:01:03 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "./keynote.h"
# include "color.h"
//# include "mlx.h"

typedef struct	s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct	s_ortho
{
	float			width;
	float			height;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	t_coord		coord;
}				t_ortho;

typedef struct	s_nb
{
	float			z_r;
	float			z_i;
	float			c_r;
	float			c_i;
}				t_nb;

typedef	struct	s_all
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				*recup;
	int				width;
	int				height;
	int				bpp;
	int				endian;
	int				sizeline;
	int				img_win;
	int				size_win_x;
	int				size_win_y;
	int				ite;
	int				*tab;
	float			mouse_x;
	float			mouse_y;
	int				button;
	float			zoom;
	t_ortho			ortho;
	t_nb			nb;
	t_coord			coord;
}				t_all;


//int		mouse_hook_julia(int x, int y, t_all *img);
void	ft_mandelbrot(t_all *point);
void	ft_julia(t_all *point);
void	ft_lapin(t_all *point);
void	event(t_all img);
void	ft_resize(t_all *imgt);
void	ft_pixel_put(t_all *point, int x, int y, uint32_t color);
void    create_img(t_all *img);
void	zoom(t_all *img);
float	init_x(t_all *img);
float	init_y(t_all *img);
int		mouse_hook(int button, int x, int y, t_all *img);
int		mouse_hook_m(int x, int y, t_all *img);
int		*ft_stock(t_all *point);
int		main(int ac, char **av);

#endif
