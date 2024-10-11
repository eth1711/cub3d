/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:28:52 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/11 18:45:47 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "math.h"
# include "mlx.h"

# define WIN_HEIGHT 512
# define WIN_WIDTH 1240

enum {
	ON_DESTROY = 17
};

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_rect
{
	t_vector	size;
	t_vector	pos;
	int			color;
}	t_rect;

typedef struct s_image
{
	void		*image;
	void		*addr;
	int			line_len;
	int			bpp;
	int			endian;
}	t_image;

typedef struct s_map
{
	char		*map;
	int			width;
	int			height;	
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_map		map;
	t_vector	player;
}	t_data;

//Events
int		on_destroy(void *param);

//Utils
int		create_trgb(int t, int r, int g, int b);
void	draw_rectangle(t_image *img, t_rect rect);

#endif
