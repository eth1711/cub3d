/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:55:11 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/26 13:54:25 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hooks(t_data *data)
{
	mlx_hook(data->window, ON_DESTROY, 0, on_destroy, NULL);
	mlx_hook(data->window, ON_KEY_DOWN, (1L), on_key_down, (void *)data);
	mlx_key_hook(data->window, on_key_up, (void *)data);
	mlx_loop_hook(data->mlx, loop, (void *)data);
}

void	init_map(t_map *map)
{
	int		m_size;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map->width = 0;
	map->length = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
			x++;
		if (x > map->width)
			map->width = x;
		y++;
		if (y > map->length)
			map->length = y;
	}
	m_size = (MMAP_RATIO * 0.01) * WIN_WIDTH;
	map->wall_size = m_size / map->width;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->image.image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(
			data->image.image,
			&data->image.bpp,
			&data->image.line_len,
			&data->image.endian
			);
}

void	init_player(t_player *player, t_map *map)
{
	while (map->map[(int)(player->pos.y)])
	{
		player->pos.x = 0;
		while (map->map[(int)(player->pos.y)][(int)(player->pos.x)]
			&& map->map[(int)(player->pos.y)][(int)(player->pos.x)] != 'P')
			player->pos.x++;
		if (map->map[(int)(player->pos.y)][(int)(player->pos.x)] == 'P')
			break ;
		player->pos.y++;
	}
	player->size = map->wall_size / 2;
	player->angle = M_PI / 2;
	player->delta = (t_vectord){cos(player->angle) * PLAYER_SPEED,
		sin(player->angle) * PLAYER_SPEED};
	player->m_down = false;
	player->m_left = false;
	player->m_right = false;
	player->m_up = false;
	player->l_left = false;
	player->l_right = false;
	player->map = true;
}

void	init(t_data *data)
{
	init_mlx(data);
	init_textures(data);
	init_hooks(data);
	init_map(&data->map);
	init_player(&data->player, &data->map);
}
