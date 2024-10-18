/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:28:52 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/18 17:48:13 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define RED 0xFF0000


typedef struct s_img {
	void	*img;
    char	*addr;
    int		bpp;
    int		len_line;
    int		endian;
}	t_img;

typedef struct s_rect {
	int		x;
	int		y;
	int 	width;
	int		height;
	int 	color;
}	t_rect;

typedef struct	s_data {
	void	*mlx;
    void	*win;
	t_img	img;
}   t_data;





#endif
