/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:28:52 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/30 19:07:02 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __linux__
#  include <X11/keysym.h>
# endif

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <time.h>

// 4096 x 2304
// 1920 x 1080
# define WIN_HEIGHT 1080  
# define WIN_WIDTH 1920
# define WALL_SIZE 64
# define MMAP_RATIO 25
// # define MMAP_SIZE (MMAP_RATIO * 0.01) * WIN_WIDTH

# define PLAYER_HITBOX 0.6
# define PLAYER_LOOK 0.1
# define PLAYER_SPEED 0.1
# define PLAYER_SIZE 9

# define DOF 8
# define FOV 60

# ifdef	__APPLE__

enum {
	ON_DESTROY = 17,
	ON_KEY_DOWN = 2,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_E = 14,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
};
# elif __linux__

enum {
	ON_DESTROY = 17,
	ON_KEY_DOWN = 2,
	KEY_ESC = XK_Escape,
	KEY_W = XK_w,
	KEY_A = XK_a,
	KEY_S = XK_s,
	KEY_D = XK_d,
	KEY_E = XK_e,
	KEY_M = XK_m,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
};
# endif

// enum parsing{
// 	NO,
// 	SO,
// 	EA,
// 	WE,
// 	F,
// 	C
// };

typedef struct s_vectori
{
	int	x;
	int	y;
}	t_vectori;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vectord;

typedef struct s_rect
{
	t_vectori	size;
	t_vectori	pos;
	int			color;
}	t_rect;

typedef struct s_ray
{
	t_vectord	start;
	t_vectord	end;
	int			len;
	double		angle;
	int			color;
}	t_ray;

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
	char		**map;
	int			wall_size;
	int			longest_wall;
}	t_map;

typedef struct s_player
{
	t_vectord	pos;
	t_vectord	delta;
	int			size;
	double		angle;
	bool		m_left;
	bool		m_right;
	bool		m_up;
	bool		m_down;
	bool		l_left;
	bool		l_right;
	bool		map;
	bool		use;
}	t_player;

// typedef struct s_textures
// {
// 	void	*north;
// 	void	*south;
// 	void	*east;
// 	void	*west;
// 	int		*floor;
// 	int		*ceiling;
// }	t_textures;

typedef struct s_parsing
{
	bool	no;
	bool	so;	
	bool	we;	
	bool	ea;	
	bool	f;
	bool	c;
}	t_parsing;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	bool		render_map;
	t_textures	textures;
	t_image		image;
	t_map		map;
	t_player	player;
}	t_data;

//Main-----------------------------------------------------

//Main
int		loop(void *param);

//Init
void	init(t_data *data);

//Player
void	move_handler(t_player *player, char **map);
void	look_handler(t_player *player);
int		check_move(t_player *player, t_map map);

//Rendering
void	draw_player(t_image *image, t_player player, int wall_size);
void	draw_background(t_image *image);
void	draw_rays(t_image *image, t_player *player, char **map);
void	draw_map(t_image *image, t_map map);

//Events
int		on_destroy(void *param);
int		on_key_down(int key, void *param);
int		on_key_up(int key, void *param);

//Utils----------------------------------------------------

//gnl
char	*get_next_line(int fd);

// Rendering Utils
int		create_trgb(int t, int r, int g, int b);
void	img_pix_put(t_image *img, int x, int y, int color);
void	draw_rectangle(t_image *img, t_rect rect);
void	draw_ray(t_image *img, t_ray ray);

#endif
