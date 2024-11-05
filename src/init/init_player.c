/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:04:09 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/05 18:58:58 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

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
	player->angle = 0;
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
