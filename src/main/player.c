/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:05 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/25 18:26:59 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// int	check_move(t_player *player, char **map)
// {
	
// }

void	move_handler(t_player *player, t_map map)
{
	int	sign;
	(void)map;
	if (player->m_up || player->m_down)
	{
		sign = 1;
		if (player->m_down)
			sign = -1;
		// if (check_move(player, map))
		// {
			player->pos.y += round(player->delta.y) * sign;
			player->pos.x += round(player->delta.x) * sign;
		// }
	}
	if (player->m_left || player->m_right)
	{
		sign = 1;
		if (player->m_left)
			sign = -1;
		// if (!check_move(player, map))
		// {
			player->pos.y += round(player->delta.x) * sign;
			player->pos.x += round(player->delta.y) * -sign;
		// }
	}
	// printf("Player angle: %lf\n", player->angle);
	// printf("Player pos: (%i, %i)\n", player->pos.x, player->pos.y);
	// printf("player->delta.x:%lf\n", player->delta.x);
	// printf("player->delta.y:%lf\n", player->delta.y);
	// printf("player next pos x:%lf\n", player->delta.x + player->pos.x);
	// printf("player next pos y:%lf\n", player->delta.y + player->pos.y);
}

void    look_handler(t_player *player)
{
    if (player->l_right || player->l_left)
	{
		if (player->l_right)
			player->angle += PLAYER_LOOK;
		else
			player->angle -= PLAYER_LOOK;
		if (player->angle > M_PI * 2)
			player->angle -= M_PI * 2;
		else if ((player->angle < 0))
			player->angle += M_PI * 2;
		player->delta.x = cos(player->angle) * PLAYER_SPEED;
		player->delta.y = sin(player->angle) * PLAYER_SPEED;
	}
}