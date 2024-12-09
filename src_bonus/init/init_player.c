/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:58:30 by pringles          #+#    #+#             */
/*   Updated: 2024/12/09 15:44:13 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angle(t_player *player, char c)
{
	if (c == 'N')
		player->angle = M_PI_2 * 3;
	if (c == 'S')
		player->angle = M_PI_2;
	if (c == 'E')
		player->angle = 0;
	if (c == 'W')
		player->angle = M_PI;
}

void	set_pos(t_player *player, t_map *map, char *c)
{
	while (map->str[(int)(player->pos.y)])
	{
		player->pos.x = 0;
		*c = map->str[(int)(player->pos.y)][(int)(player->pos.x)];
		while (*c != 0 && !ft_strchr("NSWE", *c))
		{
			player->pos.x += 1;
			*c = map->str[(int)(player->pos.y)][(int)(player->pos.x)];
		}
		if (*c && ft_strchr("NSWE", *c))
		{
			map->str[(int)player->pos.y][(int)player->pos.y] = '0';
			break ;
		}
		player->pos.y += 1;
	}
}

void	init_player(t_player *player, t_map *map)
{
	char	c;

	c = 0;
	set_pos(player, map, &c);
	set_angle(player, c);
	player->size = map->wall_size / 2;
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
