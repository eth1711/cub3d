/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:24 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/30 22:18:19 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_image *image)
{
	t_rect	background;

	background.pos.x = 0;
	background.pos.y = 0;
	background.size.y = WIN_HEIGHT;
	background.size.x = WIN_WIDTH;
	background.color = create_trgb(0, 136, 186, 71);
	draw_rectangle(image, background);
}

void	draw_player(t_image *image, t_player player, int wall_size)
{
	player.pos.x *= wall_size;
	player.pos.y *= wall_size;
	// draw_ray(image, (t_ray){
	// 	(t_vectord){player.pos.x, player.pos.y},
	// 	(t_vectord){0, 0},
	// 	player.size * 1.5,
	// 	player.angle,
	// 	create_trgb(0, 224, 16, 30)
	// });
	draw_rectangle(image, (t_rect){
		(t_vectori){player.size, player.size},
		(t_vectori){player.pos.x - player.size / 2,
		player.pos.y - player.size / 2},
		create_trgb(0, 255, 223, 18)
	});
}

void	draw_map(t_image *image, t_map	map)
{
	int		x;
	int		y;
	t_rect	wall;

	y = 0;
	wall.size = (t_vectori){map.wall_size - 1, map.wall_size - 1};
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x] && map.map[y][x] )
		{
			if (map.map[y][x] == '1')
				wall.color = create_trgb(0, 0, 0, 0);
			else if (map.map[y][x] == '0')
				wall.color = create_trgb(0, 255, 255, 255);
			wall.pos.x = x * map.wall_size;
			wall.pos.y = y * map.wall_size;
			draw_rectangle(image, wall);
			x++;
		}
		y++;
	}
}
