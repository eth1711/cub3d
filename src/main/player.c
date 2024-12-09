/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:05 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/09 10:51:01 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Move up/down along the angle:
// x: cos(angle) +/- pos.x
// y: sin(angle) +/- pos.y
// Move left/right perpendicular to the angle (everything is opposite)
// x: sin(angle) +/- pos.x
// y: cos(angle) -/+ pos.y
void	move_and_check(t_player *player, char **map, t_vectord hitbox)
{
	int	sign;

	sign = 1;
	if (player->m_up ^ player->m_down)
	{
		if (player->m_down)
			sign = -1;
		if (map[(int)(player->pos.y + hitbox.y * sign)]
			[(int)player->pos.x] != '1')
			player->pos.y += player->delta.y * sign;
		if (map[(int)player->pos.y]
			[(int)(player->pos.x + hitbox.x * sign)] != '1')
			player->pos.x += player->delta.x * sign;
	}
	if (player->m_left ^ player->m_right)
	{
		if (player->m_left)
			sign = -1;
		if (map[(int)(player->pos.y + hitbox.x * sign)]
			[(int)player->pos.x] != '1')
			player->pos.y += player->delta.x * sign;
		if (map[(int)player->pos.y]
			[(int)(player->pos.x + hitbox.y * -sign)] != '1')
			player->pos.x += player->delta.y * -sign;
	}
}

void	move_handler(t_player *player, char **map)
{
	t_vectord	hitbox;

	hitbox.x = PLAYER_HITBOX;
	hitbox.y = PLAYER_HITBOX;
	if (player->delta.x < 0)
		hitbox.x *= -1;
	if (player->delta.y < 0)
		hitbox.y *= -1;
	move_and_check(player, map, hitbox);
}

void	look_handler(t_player *player)
{
	if (player->l_right)
		player->angle += PLAYER_LOOK;
	if (player->l_left)
		player->angle -= PLAYER_LOOK;
	player->angle = reset_angle(player->angle);
	if (player->l_left ^ player->l_right)
	{
		player->delta.x = cos(player->angle) * PLAYER_SPEED;
		player->delta.y = sin(player->angle) * PLAYER_SPEED;
	}
}

// printf("Player pos: (%lf, %lf)\n", player->pos.x, player->pos.y);
// printf("Next grid valy: %c\n",map.str[(int)(player->pos.y + ( player->delta.y
// + PLAYER_HITBOX) * sign)][(int)player->pos.x]);
// printf("Next grid x: %c\n",
	// map.str[(int)player->pos.y][(int)(player->pos.x
// + (player->delta.x + PLAYER_HITBOX) * sign)]);
// printf("Next grid pos y: %i\n",
// (int)(player->pos.y + (player->delta.y + PLAYER_HITBOX) * sign));
// printf("Next grid pos x: %i\n",
	// (int)(player->pos.x + (player->delta.x + PLAYER_HITBOX) * sign));
// printf("Player angle: %lf\n", player->angle);
// printf("player->delta.x:%lf\n", player->delta.x);
// printf("player->delta.y:%lf\n", player->delta.y);
// printf("player next pos x:%lf\n", player->delta.x + player->pos.x);
// printf("player next pos y:%lf\n", player->delta.y + player->pos.y);