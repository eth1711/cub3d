/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:28:52 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/14 19:33:55 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "math.h"
# include <X11/keysym.h>
# include "mlx.h"
# include <stdio.h>
# include <time.h>

# define WIN_HEIGHT 512
# define WIN_WIDTH 1240
# define PLAYER_SPEED 10
# define PLAYER_SIZE 100

# ifdef	__APPLE__

enum {
	ON_DESTROY = 17,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};
# elif __linux__

enum {
	ON_DESTROY = 17,
	ON_KEY_DOWN = 2,
	KEY_ESC = XK_Escape,
	KEY_W = XK_w,
	KEY_A = XK_a,
	KEY_S = XK_s,
	KEY_D = XK_d
};
# endif

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

typedef struct s_player
{
	t_vector	pos;
	bool		m_up;
	bool		m_down;
	bool		m_left;
	bool		m_right;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_map		map;
	t_player	player;
}	t_data;

//Main
int		loop(void *param);

//Init
void	init(t_data *data);

//Drawing
void	draw_player(t_image *image, t_player *player);
void	draw_background(t_image *image);

//Events
int		on_destroy(void *param);
int		on_key_down(int key, void *param);
int		on_key_up(int key, void *param);

//Utils
int		create_trgb(int t, int r, int g, int b);
void	draw_rectangle(t_image *img, t_rect rect);
void	img_pix_put(t_image *img, int x, int y, int color);

#endif
