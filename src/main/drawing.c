/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:24 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/21 21:02:58 by amaligno         ###   ########.fr       */
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

void	draw_player(t_image *image, t_player *player)
{
	draw_ray(image, (t_ray){
		(t_vectord){player->pos.x, player->pos.y},
		(t_vectord){player->delta.x + player->pos.x, player->delta.y + player->pos.y},
		player->angle,
		create_trgb(0, 224, 16, 30)
	});
	draw_rectangle(image, (t_rect){
		(t_vectori){PLAYER_SIZE, PLAYER_SIZE},
		(t_vectori){(int)(player->pos.x - PLAYER_SIZE / 2),(int)(player->pos.y - PLAYER_SIZE / 2)},
		create_trgb(0, 255, 223, 18)
	});
}

void	draw_map(t_image *image, t_map map)
{
	int		x;
	int		y;
	t_rect	wall;

	y = 0;
	wall.size = (t_vectori){WALL_SIZE - 1, WALL_SIZE - 1};
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.map[y][x] == '1')
				wall.color = create_trgb(0, 0, 0, 0);
			else if (map.map[y][x] == '0')
				wall.color = create_trgb(0, 255, 255, 255);
			wall.pos.x = x * WALL_SIZE;
			wall.pos.y = y * WALL_SIZE;
			draw_rectangle(image, wall);
			x++;
		}
		y++;
	}
}
