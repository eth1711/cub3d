/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:05 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/26 20:20:10 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

//Move up/down along the angle:
//x: cos(angle) +/- pos.x 
//y: sin(angle) +/- pos.y
//Move left/right perpendicular to the angle (everything is opposite)
//x: sin(angle) +/- pos.x
//y: cos(angle) -/+ pos.y
void	move_handler(t_player *player, t_map map)
{
	int			sign;
	t_vectord	hitbox;

	sign = 1;
	hitbox.x = PLAYER_HITBOX;
	hitbox.y = PLAYER_HITBOX;
	if (player->delta.x < 0)
		hitbox.x *= -1;
	if (player->delta.y < 0)
		hitbox.y *= -1;
	if (player->m_up || player->m_down)
	{
		if (player->m_down)
			sign = -1;
		if (map.map[(int)(player->pos.y + (player->delta.y + hitbox.y) * sign)][(int)player->pos.x] != '1')
			player->pos.y += player->delta.y * sign;
		if (map.map[(int)player->pos.y][(int)(player->pos.x + (player->delta.x + hitbox.x) * sign)] != '1')
			player->pos.x += player->delta.x * sign;
	}
	if (player->m_left || player->m_right)
	{
		if (player->m_left)
			sign = -1;
		if (map.map[(int)(player->pos.y + (player->delta.y + hitbox.y) * sign)][(int)player->pos.x] != '1')
			player->pos.y += player->delta.x * sign;
		if (map.map[(int)player->pos.y][(int)(player->pos.x + player->delta.y * -sign)] != '1')
			player->pos.x += player->delta.y * -sign;
	}
	printf("Player pos: (%lf, %lf)\n", player->pos.x, player->pos.y);
	// printf("Next grid valy: %c\n", map.map[(int)(player->pos.y + ( player->delta.y + PLAYER_HITBOX) * sign)][(int)player->pos.x]);
	// printf("Next grid x: %c\n", map.map[(int)player->pos.y][(int)(player->pos.x + (player->delta.x + PLAYER_HITBOX) * sign)]);
	printf("Next grid pos y: %i\n", (int)(player->pos.y + ( player->delta.y + PLAYER_HITBOX) * sign));
	printf("Next grid pos x: %i\n", (int)(player->pos.x + (player->delta.x + PLAYER_HITBOX) * sign));
	// printf("Player angle: %lf\n", player->angle);
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