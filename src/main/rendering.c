/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:24 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/07 18:59:28 by pringles         ###   ########.fr       */
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
	background.color = FLOOR;
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

void	draw_rays_2d(t_image *image, t_ray *rays)
{
	int	i;

	i = 0;
	while (i < FOV)
	{
		draw_ray(image, rays[i]);
		i++;
	}
}

void	draw_rays_3d(t_image *image, t_ray *rays, t_map map, t_player player)
{
	t_rect	line;
	double	angle;
	double	len;
	int		i;

	(void)map;
	i = 0;
	line.size.x = WIN_WIDTH / FOV;
	line.pos.x = 0;
	while (i < FOV)
	{
		angle = player.angle - rays[i].angle;
		if (angle < 0)
			angle += M_PI * 2;
		if (angle > M_PI * 2)
			angle -= M_PI * 2;
		len = rays[i].len * cos(angle);
		line.size.y = (WALL_SIZE * WIN_HEIGHT) / len;
		if (line.size.y > WIN_WIDTH)
			line.size.y = WIN_WIDTH;
		line.pos.y = (WIN_HEIGHT - line.size.y) / 2;
		line.pos.x += line.size.x;
		if (rays[i].vert)
			line.color = create_trgb(0, 87, 48, 138);
		else
			line.color = create_trgb(0, 130, 72, 207);
		draw_rectangle(image, line);
		i++;
	}
}
