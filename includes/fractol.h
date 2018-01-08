/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 03:01:00 by aberrahm          #+#    #+#             */
/*   Updated: 2018/01/07 05:56:14 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./keynote.h"
# include "color.h"
# include "mlx.h"

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
	t_coord			coord;
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
	int				stop;
	t_coord			translate;
	t_ortho			ortho;
	t_nb			nb;
	t_coord			coord;
}				t_all;

void			ft_julia_init(t_all *point);
void			ft_julia_b(t_all *point);
void			ft_julia_n(t_all *point, int i);
void			ft_bship_b(t_all *p);
void			ft_tricks(t_all *p);
void			ft_cmp(char *str, t_all point);
void			ft_mandelbrot(t_all *point);
void			ft_julia(t_all *point);
void			ft_bship(t_all *p);
void			ft_bship_init(t_all *point);
void			ft_norm(t_all point);
void			ft_mandel_init(t_all *point);
void			ft_mandel_n(t_all *point, int i);
void			ft_mandel_n2(t_all *point, int i);
void			ft_bship_n(t_all *point, int i);
void			event(t_all img);
void			event_m(t_all img);
void			event_b(t_all img);
void			ft_resize(t_all *imgt);
void			ft_pixel_put(t_all *point, int x, int y, uint32_t color);
void			create_img(t_all *img, char *str);
void			zoom(t_all *img);
float			init_x(t_all *img);
float			init_y(t_all *img);
int				ft_key_exit(int keycode, t_all *point);
int				key_hook(int k, t_all *point);
int				key_hook_m(int keycode, t_all *point);
int				key_hook_b(int keycode, t_all *point);
int				mouse_hook(int button, int x, int y, t_all *img);
int				mouse_hook_j(int x, int y, t_all *img);
int				mouse_hook_m(int button, int x, int y, t_all *img);
int				mouse_hook_b(int button, int x, int y, t_all *img);
int				*ft_stock(t_all *point);
int				main(int ac, char **av);

#endif
