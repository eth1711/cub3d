/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:24 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/14 19:37:41 by amaligno         ###   ########.fr       */
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
	background.color = create_trgb(255, 136, 186, 71);
	draw_rectangle(image, background);
}

void	draw_player(t_image *image, t_player *player)
{
	t_rect	player_box;

	player_box.pos.x = player->pos.x - PLAYER_SIZE / 2;
	player_box.pos.y = player->pos.y - PLAYER_SIZE / 2;
	player_box.size.x = PLAYER_SIZE;
	player_box.size.y = PLAYER_SIZE;
	player_box.color = create_trgb(0, 255, 223, 18);
	draw_rectangle(image, player_box);
	img_pix_put(image, player->pos.x, player->pos.y, create_trgb(0, 255, 18, 18));
}
