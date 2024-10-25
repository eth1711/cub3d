/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:55:11 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/25 17:38:12 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player, t_map *map)
{
	player->pos.x = 0;
	player->pos.y = 0;
	while (map->map[player->pos.y])
	{
		player->pos.x = 0;
		while (map->map[player->pos.y][player->pos.x]
			&& map->map[player->pos.y][player->pos.x] != 'P')
			player->pos.x++;
		if (map->map[player->pos.y][player->pos.x] == 'P')
			break ;
		player->pos.y++;
	}
	player->angle = M_PI / 2;
	player->delta = (t_vectord){cos(player->angle) * PLAYER_SPEED,
		sin(player->angle) * PLAYER_SPEED};
	player->m_down = false;
	player->m_left = false;
	player->m_right = false;
	player->m_up = false;
	player->l_left = false;
	player->l_right = false;
}

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
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
			x++;
		if (x > map->longest_wall)
			map->longest_wall = x;
		y++;
	}
	m_size = (MMAP_RATIO * 0.01) * WIN_HEIGHT;
	map->wall_size = m_size / map->longest_wall;
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->image.image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	// data->background.image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.image, &data->image.bpp,
			&data->image.line_len, &data->image.endian);
	// data->background.addr = mlx_get_data_addr(data->background.image, &data->background.bpp,
	// &data->background.line_len, &data->background.endian);
	init_player(&data->player, &data->map);
	init_map(&data->map);
	init_hooks(data);
}
