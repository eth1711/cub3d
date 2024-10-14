/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/14 20:14:59 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_handler(t_player *player)
{
	if (player->m_up && player->pos.y - (PLAYER_SPEED + PLAYER_SIZE / 2) >= 0)
		player->pos.y -= PLAYER_SPEED;
	if (player->m_down
		&& player->pos.y + (PLAYER_SPEED + PLAYER_SIZE / 2) <= WIN_HEIGHT)
		player->pos.y += PLAYER_SPEED;
	if (player->m_left && player->pos.x - (PLAYER_SPEED + PLAYER_SIZE / 2) >= 0)
		player->pos.x -= PLAYER_SPEED;
	if (player->m_right
		&& player->pos.x + (PLAYER_SPEED + PLAYER_SIZE / 2) <= WIN_WIDTH)
		player->pos.x += PLAYER_SPEED;
}

int	loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	move_handler(&data->player);
	draw_background(&data->image);
	draw_map(&data->image, data->map);
	draw_player(&data->image, &data->player);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init(&data);
	mlx_loop(data.mlx);
}
