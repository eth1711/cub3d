/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:24 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/28 22:42:55 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_image *image)
{
	t_rect	background;

	background.pos.x = 0;
	background.pos.y = 0;
	background.size.y = WIN_HEIGHT / 2;
	background.size.x = WIN_WIDTH;
	background.color = create_trgb(0, 104, 116, 212);
	draw_rectangle(image, background);
	background.pos = (t_vectord){0, WIN_HEIGHT / 2};
	background.color = 0;
	draw_rectangle(image, background);
}

void	draw_player(t_image *image, t_player player, int wall_size)
{
	player.pos.x *= wall_size;
	player.pos.y *= wall_size;
	draw_rectangle(image, (t_rect){
		(t_vectord){player.size, player.size},
		(t_vectord){player.pos.x - player.size / 2,
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
	wall.size = (t_vectord){map.wall_size - 1, map.wall_size - 1};
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x] && map.map[y][x])
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

void	draw_rays_2d(t_image *image, t_ray *rays, int map_size)
{
	int	i;

	i = 0;
	while (i < RAYS)
	{
		rays[i].end.x *= map_size;
		rays[i].end.y *= map_size;
		rays[i].start.x *= map_size;
		rays[i].start.y *= map_size;
		rays[i].len *= map_size;
		draw_ray(image, rays[i]);
		i++;
	}
}

void	draw_rays_3d(t_image *image, t_ray *rays,
	t_player player, t_textures textures, t_map map)
{
	t_rect	line;
	double	angle;
	double	len;
	int		i;

	i = 0;
	line.size.x = WIN_WIDTH / RAYS;
	line.pos.x = 0;
	while (i < RAYS)
	{
		angle = player.angle - rays[i].angle;
		angle = reset_angle(angle);
		len = (rays[i].len * cos(angle));
		line.size.y = (WIN_HEIGHT) / len;
		line.pos.y = (WIN_HEIGHT - line.size.y) / 2;
		line.pos.x += line.size.x;
		if (rays[i].vert)
			line.color = create_trgb(0, 136, 3, 252);
		else
			line.color = create_trgb(0, 106, 0, 199);
		draw_textured_ray(image, line, rays[i], textures, map);
		i++;
	}
}
