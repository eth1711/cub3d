/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/21 16:25:18 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_handler(t_player *player)
{
	if (player->m_up)
	{
		player->pos.y += round(player->delta.y);
		player->pos.x += round(player->delta.x);
	}
	if (player->m_down)
	{
		player->pos.y -= round(player->delta.y);
		player->pos.x -= round(player->delta.x);
	}
	if (player->m_right)
	{
		player->angle += PLAYER_LOOK;
		if (player->angle > M_PI * 2)
			player->angle -= M_PI * 2;
		player->delta.x = cos(player->angle) * PLAYER_SPEED;
		player->delta.y = sin(player->angle) * PLAYER_SPEED;
	}
	if (player->m_left)
	{
		player->angle -= PLAYER_LOOK;
		if (player->angle < 0)
			player->angle += M_PI * 2;
		player->delta.x = cos(player->angle) * PLAYER_SPEED;
		player->delta.y = sin(player->angle) * PLAYER_SPEED;
	}
	printf("Player angle: %lf\n", player->angle);
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
	data.map.map = (char *[]){"1111111\n",
		"1000001\n",
		"1000001\n",
		"1000001\n",
		"1000001\n",
		"1111111\n",
		NULL
	};
	mlx_loop(data.mlx);
}
