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
# include "../libft/libft.h"
# include "./keynote.h"
# include "color.h"
# include "mlx.h"

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
}				t_all;

void    create_img(t_all *img);

#endif